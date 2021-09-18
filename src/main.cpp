#include "template.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string_view>
#include <filesystem>

#include <fmt/format.h>


struct desc {
    std::string title;
    std::string description;
};


desc read_desc_file(const std::string& path) {
    desc fres;
    // Open file
    std::ifstream desc_file(path);
    // Check file
    if (!desc_file) {
        throw std::runtime_error("Failed to open "+path+" for reading");
    }
    // Read first line (title)
    std::getline(desc_file, fres.title);
    // Read description
    fres.description = std::string(std::istreambuf_iterator<char>{desc_file}, {}); // A mess of code
    // Return function result
    return fres;
}

desc handle_media_dir(const std::filesystem::path& media_dir) {
    // Open output file for writing
    std::ofstream output(media_dir/"index.html");
    // Get directory description
    auto media_dir_desc = read_desc_file(media_dir/"desc.txt");
    // Write out top
    output << fmt::format(Template::top, media_dir_desc.title, media_dir_desc.description);
    // Iterate through input dir
    for (const auto& file : std::filesystem::directory_iterator(media_dir)) {
        // Skip .html and .txt files
        auto ext = file.path().extension();
        if (ext == ".html" || ext == ".txt") {
            continue;
        }
        // Get description
        desc file_desc;
        if (file.is_directory()) {
            // Handle directory
            file_desc = handle_media_dir(file);
        } else {
            // Handle file
            file_desc = read_desc_file(file.path().string()+".txt");
        }
        // Write out entry
        output << fmt::format(Template::content, file_desc.title, file_desc.description, file.path().filename().string());
    }
    // Write out bottom
    output << Template::bottom;
    // Return description of directory
    return media_dir_desc;
}

int main(int argc, char **argv) {
    // Get args
    if (argc != 2) {
        // Print usage
        std::cout << "Usage: " << argv[0] << " <media dir>" << std::endl;
        return EXIT_FAILURE;
    }
    // Handle given media dir
    handle_media_dir(argv[1]);
}
