#pragma once
#include <Windows.h>
#include <windows.graphics.h>
#include "Programmer.h"
#include "vector.h"
#include <conio.h>

//char GetComand()
//{
//    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
//    DWORD mode;
//    BOOL result = GetConsoleMode(hstdin, &mode);
//    DWORD newmode = mode & (0xFFFFFFFF - 2 - 4);
//    result = SetConsoleMode(hstdin, newmode);
//    return std::cin.get();
//}

//char Save(int key);
//HHOOK hook;
//extern char prevProg[256];
//KBDLLHOOKSTRUCT kbStruct;
//LRESULT _stdcall HookCallback(int nCode, WPARAM wParam, LPARAM IParam)
//{
//    if (nCode >= 0)
//    {
//        if (wParam == WM_KEYDOWN)
//        {
//            kbStruct = *((KBDLLHOOKSTRUCT*)IParam);
//            Save(kbStruct.vkCode);
//        }
//    }
//
//    return CallNextHookEx(hook, nCode, wParam, IParam);
//}
//
//char Save(int key)
//{
//    HKL keyboardLayout;
//    DWORD threadId;
//    keyboardLayout = GetKeyboardLayout(threadId);
//    if (key == 1 || key == 2)
//        return '1';
//    std::cout << key << std::endl;
//    char crrKey;
//    bool lower = ((GetKeyState(VK_CAPITAL) & 0x0001) != 0);
//    if ((GetKeyState(VK_SHIFT) & 0x1000) != 0 || (GetKeyState(VK_LSHIFT) & 0x1000) != 0||(GetKeyState(VK_RSHIFT) & 0x1000) != 0)
//    {
//        lower = !lower;
//    }
//
//    crrKey = MapVirtualKeyExA(key, MAPVK_VK_TO_CHAR, keyboardLayout);
//    if (!lower)
//    {
//        tolower(crrKey);
//    }
//    return crrKey;
//}

void menu()
{
    std::cout << "All comands:\n";
    std::cout << "'m' - create group random\n";
    std::cout << "'+' - add element\n";
    std::cout << "'-' - delete element\n";
    std::cout << "'z' - serch index\n";
    std::cout << "'s' - Print all\n";
    std::cout << "'q' - end\n";
}

class EventListener
{
public:
    virtual void onCommandCreateGroup(int numElements) = 0;
    virtual void onCommandAddElement(const std::string& name, int age, float wages, const std::string& position) = 0;
    virtual void onCommandRemoveElement() = 0;
    virtual void onCommandPrintGroupInfo() = 0;
    virtual void onCommandPrintElementName(int index) = 0;
    virtual void onCommandQuit() = 0;
};


class EventManager
{
private:
    EventListener* listener;
public:
    void setEventListener(EventListener* eventListener) {
        listener = eventListener;
    }

    void processCommands() 
    {
        char comand;
        int numElements, index;
        std::string name, pozition;
        int age;
        float wages;
        //MSG massage;
        while (true)
        {
            menu();
            //std::cin >> comand;
            //comand = getchar();
            //comand = GetComand();
            //int code;
            comand = _getch();
            /*code = static_cast<int>(comand);*/

            switch (comand)
            {
            case 'm':
                std::cout << "Numbers: "; std::cin >> numElements;
                listener->onCommandCreateGroup(numElements); break;
            case '+':
                std::cout << "Name: "; std::cin >> name; std::cout << "Age: "; std::cin >> age; std::cout << "wages: "; std::cin >> wages; std::cout << "poz: "; std::cin >> pozition;
                listener->onCommandAddElement(name, age, wages, pozition); break;
            case '-':
                listener->onCommandRemoveElement();break;
            case 's':
                listener->onCommandPrintGroupInfo();break;
            case 'z':
                std::cout << "Index: ";std::cin >> index;
                listener->onCommandPrintElementName(index);break;
            case 'q':
                listener->onCommandQuit();
            default:
                std::cout << "Unknown command." << std::endl;
            }
            system("pause");
            system("cls");
        }
    }
};

class Group : public EventListener
{
private:
    vector<Programmer> elements;
public:
    void onCommandCreateGroup(int numElements) override {
        //vector<Programmer> temp(numElements);
        //elements = temp;
        //std::cout << "Created a group with " << numElements << " elements." << std::endl;
        std::string Name, Pos;
        int age;
        float wages;
        char* NAME[5] = { (char*)"Dima", (char*)"Mark", (char*)"Valera", (char*)"Denis", (char*)"Rita" };
        char* POS[5] = { (char*)"Web_disayner", (char*)"Front_programmer", (char*)"Back_programmer", (char*)"Fulpack_programmer", (char*)"Module_programmer" };
        for (int i = 0; i < numElements; ++i)
        {
            age = rand() % (40 - 18 + 1) + 18;
            wages = (5 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (25 - 5))))*10000;
            Name = NAME[rand() % 5];
            Pos = POS[rand() % 5];
            Programmer el(Name, age, wages, Pos);
            el.Print();
            elements.push_back(el);
        }
        std::cout << "Created a group with " << numElements << " elements." << std::endl;
        //system("pause");
        //system("cls");
    }
    void onCommandAddElement(const std::string& name, int age, float salary, const std::string& position) override {
        Programmer temp(name, age, salary, position);
        elements.push_back(temp);
        std::cout << "Added element: " << name << std::endl;
        /*system("pause");
        * 
        system("cls");*/
    }
    void onCommandRemoveElement() override{
        if (!elements.empty()){
            elements.pop_back();
            std::cout << "Removed the last element." << std::endl;
        }
        else{
            std::cout << "Group is empty." << std::endl;
        }
        //system("pause");
        //system("cls");
    }
    void onCommandPrintGroupInfo() override {
        if (elements.size() != 0)
        {
            std::cout << "Group information:" << std::endl;
            for (int i = 0; i < elements.size(); ++i)
            {
                Programmer temp = elements[i];
                temp.Print();
                Sleep(500);
            }
        }
        else
            std::cout << "add some elements\n";
        //system("pause");
        //system("cls");
    }
    void onCommandPrintElementName(int index) override {
        if (index >= 0 && index < elements.size()) {
            std::cout << "Name of element " << index << ": "; 
            Programmer temp = elements[index];
            temp.Print();
        }
        else {
            std::cout << "Invalid element number." << std::endl;
        }
        //system("pause");
        //system("cls");
    }

    void onCommandQuit() override {
        std::cout << "Exiting the program." << std::endl;
        exit(0);
    }
};
class dialog: public Group
{
public:
    void Start()
    {
        EventManager eventManager;
        Group group;

        eventManager.setEventListener(&group);
        eventManager.processCommands();
    }
};
