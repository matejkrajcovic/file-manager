#include "file_list_view.h"
#include <gtkmm.h>
#include <boost/filesystem.hpp>

FileListView::FileListView() {
    model = Gtk::ListStore::create(columns);

    view.set_model(model);
    view.append_column("File name", columns.fileName);

    add(view);
}

void FileListView::setDirectory(std::string directory) {
    model->clear();

    boost::filesystem::path path(directory);
    boost::filesystem::directory_iterator dir_iterator(path);

    for (auto entry : dir_iterator) {
        Gtk::TreeModel::Row row = *(model->append());
        row[columns.fileName] = entry.path().filename().c_str();
    }
}
