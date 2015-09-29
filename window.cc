#include "window.h"
#include <boost/filesystem.hpp>

Window::Window() {
    set_border_width(5);
    set_title("File Manager");

    fileListView.setDirectory("/");
    add(fileListView);

    show_all_children();
}

Window::~Window() {}
