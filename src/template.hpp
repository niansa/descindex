#ifndef _TEMPLATE_HPP
#define _TEMPLATE_HPP
#include <string_view>



namespace Template {
constexpr std::string_view
doctype = R"(<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">)";

namespace Listing {
constexpr std::string_view
top = R"(
<html>
    <head>
        <title>{0}</title>
    </head>
    <body>
        <h1>{0}</h1>
        <p>{1}</p>
        <br />
)",
content_file = R"(
        <br />
        <h3>{0}</h3>
        <p>{1}</p>
        <p><a href="{2}">Open</a> - <a href="{2}_preview.html">Preview</a></p>
)",
content_dir = R"(
        <br />
        <h3>[DIR] {0}</h3>
        <p>{1}</p>
        <p><a href="{2}">Open</a></p>
)",
bottom = R"(
    <br />
    <p><i><a href="..">One up</a></i></p>
    </body>
</html>
)";
}

namespace Preview {
constexpr std::string_view
top = R"(
<html>
    <head>
        <title>{0} - Preview</title>
    </head>
    <body>
        <p><a href=".">Leave preview</a></p>
        <h1>{0}</h1>
        <p>{1}</p>
        <br />
)",
content = R"(
         <p><a href="{0}">Open</a></p>
         <iframe src="{0}"></iframe>
)",
bottom = R"(
    </body>
</html>
)";
}
}
#endif
