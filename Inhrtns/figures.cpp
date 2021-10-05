#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

// Базовый *абстрактный* класс фигуры
class Figure 
{
  protected:
    float weight_;
  public:
    // Все эти методы будут доступны в дочерних классах
    float getWeight() 
    { return weight_; }

    void setWeight(float weight) 
    { weight_ = weight; }

    // Чисто виртуальный метод.
    // Его реализация *обязана* быть 
    // в дочернем *неабстрактном* классе.
    virtual float square() = 0;
};

// Класс треугольника
class Triangle: public Figure 
{
  private:
    float a_, b_, c_;

  public:
    Triangle(float a, float b, float c) 
    {
      a_ = a;
      b_ = b;
      c_ = c;
    }

    float getA() { return a_; }
    float getB() { return b_; }
    float getC() { return c_; }

    // Реализация виртуального метода
    float square() 
    {
      float p = (a_ + b_ + c_) / 2;
      return sqrtf(p * (p - a_) * (p - b_) * (p - c_));
    }
};

// Класс прямоугольника
class Rectangle: public Figure 
{
  private:
    float a_, b_;

  public:
    Rectangle(float a, float b) 
    {
      a_ = a;
      b_ = b;
    }

    float getA() { return a_; }
    float getB() { return b_; }

    // Реализация виртуального метода
    float square() { return a_ * b_; }
};

// Класс окружности
class Circle: public Figure 
{
  private:
    float r_;

  public:
    Circle(float r) 
    { r_ = r; }

    float getR() { return r_; }

    // Реализация виртуального метода
    float square() 
    { return M_PI * r_ * r_; }
};

int main() 
{
  // Массив указателей для хранения объектов. 
  // Массив содержит указатели на объекты родительского 
  // типа Figure, хотя на самом деле по соответствующим 
  // адресам в памяти буду лежать объекты производных 
  // типов (Triangle, Rectangle, Circle).
  Figure* figs[15];

  // Создаём 15 фигур различных типов и сохраняем указатели на них
  for (int i = 0; i < 15; i += 3) 
  {
    figs[i] = new Triangle(1, 1, 1);
    figs[i + 1] = new Rectangle(1, 2);
    figs[i + 2] = new Circle(1);
  }

  // Вызываем метод родительского класса
  for (int i = 0; i < 15; ++i)
    figs[i]->setWeight(1);

  // Вызываем виртуальный метод. Для каждого 
  // объекта будет вызвана соответствующая реализация.
  for (int i = 0; i < 4; i++)
  {
    cout << " Figure " << i << " square: ";
    cout << figs[i]->square() << endl;
  }

  // Нельзя создать экземпляр абстрактного 
  // класса (т.е. того, который имеет чисто 
  // виртуальные методы).
  // Поэтому объявление ниже ошибочно.
  // 
  // Figure fig;
    
  for (int i = 0; i < 15; ++i)
    delete figs[i];

  return 0;
}