all:
	g++ main.cc window.cc -o file_manager `pkg-config gtkmm-3.0 --cflags --libs`
