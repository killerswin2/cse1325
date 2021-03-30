#include "parent.h"
#include "student.h"
#include "mainwin.h"
#include "entrydialog.h"

Mainwin::Mainwin() : display{new Gtk::Label}, filename{"untitled.smart"}{
    set_default_size(400,200);
    set_title("SMART");
    //Vertical Box
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    //MENU
    Gtk::MenuBar *menubar= Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    
    //TOOLBAR
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //TOOLBAR NEW 
    Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_school_button->set_tooltip_markup("Create a new school");
    new_school_button->signal_clicked().connect([this]{this->on_new_school_click();});
    toolbar->append(*new_school_button);

    //TOOLBAR OPEN 
    Gtk::ToolButton *open_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    open_button->set_tooltip_markup("open a school file");
    open_button->signal_clicked().connect([this]{this->on_open_click();});
    toolbar->append(*open_button);

    //TOOLBAR SAVE 
    Gtk::ToolButton *save_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    save_button->set_tooltip_markup("save current session");
    save_button->signal_clicked().connect([this]{this->on_save_click();});
    toolbar->append(*save_button);

    //TOOLBAR SAVE AS
    Gtk::ToolButton *save_as_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    save_as_button->set_tooltip_markup("save as");
    save_as_button->signal_clicked().connect([this]{this->on_save_as_click();});
    toolbar->append(*save_as_button);

    //TOOLBAR INSERT STUDENT
    Gtk::Image *student_image = Gtk::manage(new Gtk::Image{"student.png"});
    Gtk::ToolButton *student_insert_button = Gtk::manage(new Gtk::ToolButton(*student_image));
    student_insert_button->set_tooltip_markup("create a student");
    student_insert_button->signal_clicked().connect([this]{this->on_new_student_click();});
    toolbar->append(*student_insert_button);

    //TOOLBAR INSERT PARENT
    Gtk::Image *parent_image = Gtk::manage(new Gtk::Image("parent.png"));
    Gtk::ToolButton *parent_insert_button = Gtk::manage(new Gtk::ToolButton(*parent_image));
    parent_insert_button->set_tooltip_markup("create a parent");
    parent_insert_button->signal_clicked().connect([this]{this->on_new_parent_click();});
    toolbar->append(*parent_insert_button);

    //TOOLBAR RELATE STUDENT PARENT
    Gtk::Image *relate_image = Gtk::manage(new Gtk::Image("relate.png"));
    Gtk::ToolButton *relate_student_parent_button = Gtk::manage(new Gtk::ToolButton(*relate_image));
    relate_student_parent_button->set_tooltip_markup("relate a student to a parent");
    relate_student_parent_button->signal_clicked().connect([this]{this->on_student_parent_click();});
    toolbar->append(*relate_student_parent_button);

    //Label
    display->set_hexpand(true);
    display->set_vexpand(true);
    show_data();
    vbox->pack_start(*display,Gtk::PACK_SHRINK,0);

    //FILE
    Gtk::MenuItem *file_menu = Gtk::manage(new Gtk::MenuItem("File"));
    menubar->append(*file_menu);
    Gtk::Menu *file_sub_menu = Gtk::manage(new Gtk::Menu());
    file_menu->set_submenu(*file_sub_menu);

    //FILE -> NEW SCHOOl
    Gtk::MenuItem *new_school_menu_item = Gtk::manage(new Gtk::MenuItem("New School"));
    new_school_menu_item->signal_activate().connect([this]{this->on_new_school_click();});
    file_sub_menu->append(*new_school_menu_item);

    //FILE -> SAVE
    Gtk::MenuItem *save_menu_item = Gtk::manage(new Gtk::MenuItem("Save"));
    save_menu_item->signal_activate().connect([this]{this->on_save_click();});
    file_sub_menu->append(*save_menu_item);

    //FILE -> SAVE AS
    Gtk::MenuItem *save_as_menu_item = Gtk::manage(new Gtk::MenuItem("Save As"));
    save_menu_item->signal_activate().connect([this]{this->on_save_as_click();});
    file_sub_menu->append(*save_as_menu_item);

    //FILE -> OPEN
    Gtk::MenuItem *open_menu_item = Gtk::manage(new Gtk::MenuItem("Open"));
    open_menu_item->signal_activate().connect([this]{this->on_open_click();});
    file_sub_menu->append(*open_menu_item);

    //FILE -> QUIT
    Gtk::MenuItem *quit_menu_item = Gtk::manage(new Gtk::MenuItem("Quit"));
    quit_menu_item->signal_activate().connect([this]{this->on_quit_click();});
    file_sub_menu->append(*quit_menu_item);
    
    //INSERT
    Gtk::MenuItem *insert_menu = Gtk::manage(new Gtk::MenuItem("Insert"));
    menubar->append(*insert_menu);
    Gtk::Menu *insert_sub_menu = Gtk::manage(new Gtk::Menu());
    insert_menu->set_submenu(*insert_sub_menu);

    //INSERT -> NEW STUDENT
    Gtk::MenuItem *new_student_menu_item = Gtk::manage(new Gtk::MenuItem("New Student"));
    new_student_menu_item->signal_activate().connect([this]{this->on_new_student_click();});
    insert_sub_menu->append(*new_student_menu_item);

    //INSERT -> NEW PARENT
    Gtk::MenuItem *new_parent_menu_item = Gtk::manage(new Gtk::MenuItem("New Parent"));
    new_parent_menu_item->signal_activate().connect([this]{this->on_new_parent_click();});
    insert_sub_menu->append(*new_parent_menu_item);

    //RELATE
    Gtk::MenuItem *relate_menu = Gtk::manage(new Gtk::MenuItem("Relate"));
    menubar->append(*relate_menu);
    Gtk::Menu *relate_sub_menu = Gtk::manage(new Gtk::Menu());
    relate_menu->set_submenu(*relate_sub_menu);

    //RELATE -> STUDENTS TO PARENTS
    Gtk::MenuItem *students_to_parents = Gtk::manage(new Gtk::MenuItem("Student to Parent"));
    students_to_parents->signal_activate().connect([this] {this->on_student_parent_click();});
    relate_sub_menu->append(*students_to_parents);

    //HELP
    Gtk::MenuItem *help_menu = Gtk::manage(new Gtk::MenuItem("Help"));
    menubar->append(*help_menu);
    Gtk::Menu *help_sub_menu = Gtk::manage(new Gtk::Menu());
    help_menu->set_submenu(*help_sub_menu);

    //HELP -> ABOUT
    Gtk::MenuItem *about_menu_item = Gtk::manage(new Gtk::MenuItem("About"));
    about_menu_item->signal_activate().connect([this]{this->on_about_click();});
    help_sub_menu->append(*about_menu_item);

    vbox->show_all();
}
Mainwin::~Mainwin(){ }

void Mainwin::show_data(){
    Glib::ustring label_text;

    label_text = "Students\n";

    //display students
    for(int i = 0; i< students.size(); ++i){
        label_text += students[i].full_info()  + "\n";
    }

    label_text += "\n\nParents\n";
    //display parents
    for(int i = 0; i< parents.size(); ++i){
        label_text += parents[i].full_info()  + "\n";
    }
    display->set_label(label_text);
}


void Mainwin::on_new_school_click(){
    students.erase(students.begin(), students.end());
    parents.erase(parents.begin(), parents.end());
    show_data();
}

void Mainwin::on_new_student_click(){
    //Student Name 
    Glib::ustring name;
    EntryDialog Name{*this,"Student name?"};
    Name.run();
    name = Name.get_text();

    //Student Email
    Glib::ustring email;  
    EntryDialog Email{*this,"Student email?"};
    Email.run();
    email = Email.get_text();
    
    //Student Grade
    std::string grade_string;
    EntryDialog Grade{*this,"Student grade"};
    Grade.run();
    grade_string = Grade.get_text();
    int grade = std::stoi(grade_string);
    
    //Create Student
    students.push_back(Student{name, email, grade });
    show_data();
}
void Mainwin::on_new_parent_click(){
    //Parent Name 
    Glib::ustring name;
    EntryDialog Name{*this,"Parent name?"};
    Name.run();
    name = Name.get_text();

    //Student Email
    Glib::ustring email;  
    EntryDialog Email{*this,"Parent email?"};
    Email.run();
    email = Email.get_text();
    
    //Create Parent
    parents.push_back(Parent{name, email});
    show_data();
}

void Mainwin::on_student_parent_click(){
    //Student Dialog
    EntryDialog student_name{*this, "Student Name?"};
    std::string student_names;
    for(int i = 0; i < students.size(); ++i){
        student_names += std::to_string(i) + " " + students[i].to_string() + "\n";
    }
    student_name.set_secondary_text(student_names);
    student_name.run();
    
    //Student index
    std::string student_index_string;
    student_index_string = student_name.get_text();
    int student_index = std::stoi(student_index_string);

    //Parent Dialog
    EntryDialog parent_name{*this, "Parent Name?"};
    std::string parent_names;
    for(int i = 0; i< parents.size(); ++i){
        parent_names += std::to_string(i) + " " + parents[i].to_string() + "\n";
    }
    parent_name.set_secondary_text(parent_names);
    parent_name.run();

    //Parent index
    std::string parent_index_string;
    parent_index_string = parent_name.get_text();
    int parent_index = std::stoi(parent_index_string);


    //Relate Student to Parent
    parents[parent_index].add_student(students[student_index]);

    //Relate Parent to Student
    students[student_index].add_parent(parents[parent_index]);

    //Update Display
    show_data();

}  
void Mainwin::on_quit_click(){
    close();   
}


void Mainwin::on_save_click(){
    //using try catch
    try{
        //open output file using filename
        std::ofstream ost{filename};
        if(!ost){
            throw std::runtime_error{"Bad File open"};
        }

        //write size of student vector
        ost << std::to_string(students.size()) << std::endl;

        //for each student call Student::save
        for(int i = 0; i< students.size(); ++i){
            students[i].save(ost);
        }

        //write size of parent vector
        ost << std::to_string(parents.size()) << std::endl;

        //for each parent call parent::save
        for(int i = 0; i< parents.size(); ++i){
            parents[i].save(ost);
        }

    }catch(std::exception &e){
        Gtk::MessageDialog{*this, e.what()}.run();
    }

}

void Mainwin::on_save_as_click(){
    //FileChooserDialog with default filter
    Gtk::FileChooserDialog file{*this, "Save As", Gtk::FILE_CHOOSER_ACTION_SAVE};
    
    //SMART file filter
    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern("*.smart");
    file.add_filter(filter_smart);
    
    //all files filter
    auto filter_all = Gtk::FileFilter::create();
    filter_all->set_name("All files");
    filter_all->add_pattern("*");
    file.add_filter(filter_all);

    //set filename
    file.set_filename(filename);

    //add buttons to filedialog
    file.add_button("Save", 1);
    file.add_button("Cancel", 0);

    //if save set Mainwin::filename to filename in dialog
    if(file.run() == 1){
        //get filename
         filename = file.get_filename();

        //call Mainwin::save_on_click
        on_save_click();
    }

    //if cancel return nothing

}

void Mainwin::on_open_click(){
    //FileChooserDialog with default filter
    Gtk::FileChooserDialog file{*this, "Open", Gtk::FILE_CHOOSER_ACTION_OPEN};
    
    //SMART file filter
    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern("*.smart");
    file.add_filter(filter_smart);
    
    //all files filter
    auto filter_all = Gtk::FileFilter::create();
    filter_all->set_name("All files");
    filter_all->add_pattern("*");
    file.add_filter(filter_all);

    //set filename
    file.set_filename(filename);

    //add buttons to filedialog
    file.add_button("Open", 1);
    file.add_button("Cancel", 0);

    //if open set Mainwin::filename to filename in dialog
    if(file.run() == 1){
        //get filename
        filename = file.get_filename();

        //try opening input file with filename
        try{
            //clear school info of current session
            on_new_school_click();
            std::ifstream input{filename};
            if(!input){
                throw std::runtime_error{"Error Opening File"}; 
            }
            //read the size of student
            int student_vector_size;
            input >> student_vector_size;

            //for each student in file, pushback to student vector
            for(int i = 0; i < student_vector_size; ++i){
                students.push_back(Student{input});
            }

            //read the size of parent
            int parent_vector_size;
            input >> parent_vector_size;

            //for each parent in file, pushback to parent vector
            for(int i = 0; i < parent_vector_size; ++i){
                parents.push_back(Parent{input});
            }

        }catch(std::exception &e){
            Gtk::MessageDialog{*this, e.what()}.run();
        }
    }
    
    //if cancel or other, return nothing
    show_data();
}

void Mainwin::on_about_click(){
    Gtk::AboutDialog about;

    //avoid discouring warning
    about.set_transient_for(*this);

    //add title
    about.set_program_name("Smart");

    //add verison
    about.set_version("Version 1.03");

    //custom logo
    auto logo = Gdk::Pixbuf::create_from_file("smart_logo.png");
    about.set_logo(logo);

    //copyright
    about.set_copyright("Copyright 2021");

    //software license
    about.set_license_type(Gtk::License::LICENSE_MIT_X11);
    //set authors
    std::vector<Glib::ustring> author = {"Ellis Nielsen"};
    about.set_authors(author);

    //credit
    std::vector<Glib::ustring> art = {"Logo and icons By Ellis Nielsen."};
    about.set_artists(art);

    about.run();

}