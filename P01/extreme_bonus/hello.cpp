#include <gtkmm.h>

int main(void){
	
	auto app = Gtk::Application::create("uta.cse.ellis.nielsen");
	Glib::ustring message = "Hello Ellis!";
	Gtk::MessageDialog{message}.run();		//take message and run
	
	return app->run();						// i did not think that this would work.
}
