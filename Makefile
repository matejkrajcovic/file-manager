all:
	g++ main.cc window.cc file_list_view.cc -o file_manager -std=c++11 -lboost_system -lboost_filesystem `pkg-config gtkmm-3.0 --cflags --libs`
