#include "window.h"
#include <boost/filesystem.hpp>

Window::Window() {
    set_border_width(5);
    set_title("File Manager");

    scrolledWindow.add(fileListView);
    add(scrolledWindow);

    fileListModel = Gtk::ListStore::create(fileListColumns);

    fileListView.set_model(fileListModel);

    boost::filesystem::path path("/");
    boost::filesystem::directory_iterator dir_iterator(path);

    for (auto entry : dir_iterator) {
        Gtk::TreeModel::Row row = *(fileListModel->append());
        row[fileListColumns.fileName] = entry.path().filename().c_str();
    }

    fileListView.append_column("File name", fileListColumns.fileName);

    show_all_children();
}

Window::~Window() {}
