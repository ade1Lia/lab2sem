#include <iostream>
#include <vector>
#include <math.h>

class Fig
{
protected:
    std::string m_color;
    double m_area;
    std::vector <int> m_size;
    int X, Y;
public:
    Fig(const std::string& color, std::vector<int>* size, int x, int y) : m_color(color), m_size(*size), X(x), Y(y){}
    virtual double GetArea()
    {
        return m_area;
    }
    virtual ~Fig(){}
};
class Circle: public Fig
{
public:
    Circle(const std::string& color, std::vector<int>* size, int x, int y) : Fig(color, size, x,y) {}
    virtual ~Circle(){}
    double GetArea() override
    {
        m_area = acos(-1)*pow(m_size[0],2);
        std::cout << m_area << "\n";
    }
};
class Triangle: public Fig
{
public:
    Triangle(const std::string& color, std::vector<int>* size, int x, int y) : Fig(color, size, x,y) {}
    virtual ~Triangle(){}
    double GetArea() override
    {
        double p = (m_size[0]+m_size[1]+m_size[2])/2;
        m_area = sqrt(p*(p-m_size[0])*(p-m_size[1])*(p-m_size[2]));
        std::cout << m_area << "\n";
    }
};
class Rectangle: public Fig
{
public:
    Rectangle(const std::string& color, std::vector<int>* size, int x, int y) : Fig(color, size, x,y) {}
    virtual ~Rectangle(){}
    double GetArea() override
    {
        m_area = m_size[0]*m_size[1];
    }
};

int main()
{
    std::vector <int> v ={3,4,5};
    Triangle f("Green", &v,12,13);
    f.GetArea();
}