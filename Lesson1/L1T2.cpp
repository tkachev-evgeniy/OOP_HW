#include <iostream>
#include <cstdint>

using namespace std;

class RGBA{
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA(): m_red(0), m_green(0), m_blue(0), m_alpha(255) {
    }
    RGBA (uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
        m_red = red;
        m_green = green;
        m_blue = blue;
        m_alpha = alpha;
    }
    void print(){
        //“ип данных uint8_t при выводе через cout показывает не числа а буквы с соответсвующим номером. ѕоэтому перед выводом пришлось сделать приведение к обычному int.
		
        int r, g, b, a;
        r=m_red;
        g=m_green;
        b=m_blue;
        a=m_alpha;
        cout << "R:" << r << " G:" << g << " B:" << b << " A:" << a << endl;
    }

};

int main()
{
    RGBA Khaki (195,176,145,255);
    Khaki.print();
    return 0;
}
