#ifndef _TEMPLATE_HPP
#define _TEMPLATE_HPP
#include <string_view>



namespace Template {
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
content = R"(
        <br />
        <h3>{0}</h3>
        <p>{1}</p>
        <a href="{2}">Open</a>
)",
bottom = R"(
    </body>
</html>
)";
}
#endif
