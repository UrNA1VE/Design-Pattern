#include<iostream>
#include<vector>

using namespace std;

class Editor {
public:
    bool copy() {
        cout<<"Select do you want to copy"<<endl;
        getline(cin,s);
        flag = true;

        return true;
    }

    bool cut() {
        cout<<"Select do you want to cut"<<endl;
        getline(cin,s);
        flag = false;

        return true;

    }

    void check() {
        cout<<s<<endl;
    }

    bool paste() {
        cout<<s<<endl;
        if (!flag) {
            s = "";
        }

        return true;
    }

private:
    string s;
    bool flag;
};


class Command {
public:
    virtual bool execute() = 0;
};

class CopyCommand: public Command {

public:

    CopyCommand(Editor* e): editor(e) {};
    bool execute() override {
        editor->copy();
        return true;
    }


private:
    Editor* editor;
};


class CutCommand: public Command {

public:

    CutCommand(Editor* e): editor(e) {};
    bool execute() override {
        editor->cut();
        return true;
    }


private:
    Editor* editor;
};

class PasteCommand: public Command {

public:
    PasteCommand(Editor* e): editor(e) {};
    bool execute() override {
        editor->paste();
        return true;
    }


private:
    Editor* editor;
};

class Invoker {
public:
    void setCommand(Command* c) {
        command = c;
    }

    void execute() {
        if (command != nullptr) {
            command->execute();
        }
    }
private:
    Command* command;
};

int main() {
    Editor* editor = new Editor();
    PasteCommand* p = new PasteCommand(editor);
    CutCommand* cut = new CutCommand(editor);
    CopyCommand* copy = new CopyCommand(editor);
    Invoker* invoker = new Invoker();
    invoker->setCommand(copy);
    invoker->execute();
    invoker->setCommand(p);
    invoker->execute();
    invoker->setCommand(cut);
    invoker->execute();
    invoker->setCommand(p);
    invoker->execute();
    return 0;
}
