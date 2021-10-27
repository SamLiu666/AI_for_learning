/*
 * @Description: 
 * @Version: 2.0
 * @Autor: lxp
 * @Date: 2021-10-27 12:32:44
 * @LastEditors: lxp
 * @LastEditTime: 2021-10-27 12:47:29
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Screen;

class Window_mgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;
	inline void clear(ScreenIndex);

private:
	std::vector<Screen> screens;
};

class Screen {

    friend void Window_mgr::clear(ScreenIndex);
    
public:
    using pos = string::size_type;
    Screen() {;}
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd, c) { }
    
    char get() const {return contents[cursor];}
    char get(pos r, pos c) const { return contents[r*width + c]; }

    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);

    const Screen& display(std::ostream &os) const { do_display(os); return *this; }
    Screen& display(std::ostream &os) { do_display(os); return *this; }

private:
    void do_display(std::ostream &os) const { os << contents; }
private:
    pos height = 0, width = 0, cursor = 0;
    string contents;

};

inline void Window_mgr::clear(ScreenIndex i)
{
	Screen& s = screens[i];
	s.contents = std::string(s.height*s.width,' ');
}

inline Screen& Screen::move(pos r, pos c)
{
    cursor = r*width + c;
    return *this;
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
    contents[r*width+c] = ch;
    return *this;
}


int main()
{
    Screen myScreen(4, 4, 'X');
    myScreen.move(1, 0).set(' ').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";

    return 0;
}
