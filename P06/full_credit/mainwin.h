#ifndef __MAINWIN_H
#define __MAINWIN_H
#include "person.h"
//#include "parent.h"
//#include "student.h"
#include <gtkmm.h>


class Parent;
class Student;

class Mainwin : public Gtk::Window{
    private:
        Gtk::Label *display;
        std::vector<Student> students;
        std::vector<Parent> parents;
        void show_data();
    protected:
        void on_new_school_click();
        void on_new_student_click();
        void on_new_parent_click();
        void on_student_parent_click();
        void on_quit_click();
    public:
        Mainwin();
        virtual ~Mainwin();
};



#endif