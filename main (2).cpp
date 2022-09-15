#include <iostream>
#include <cassert> // для assert()


//============================================================================================================

class Figure
{
protected:
    double w, h, a;
public:
    Figure(double width = 0, double hight = 0, double alfa = 0) { w = width; h = hight; a = alfa; }

    virtual double area() = 0;
    virtual ~Figure(){}
};

class Parallelogram : public Figure
{
public:
    Parallelogram (double width = 3, double hight = 5, double alfa = 55)
    : Figure (width, hight, alfa){};

     double area()
    {
        return ( w * h * sin(a));
    }
    ~Parallelogram(){}
};

class Rectangle : public Parallelogram
{
public:
    Rectangle ( double width = 5, double hight = 6, double alfa = 90)
    : Parallelogram (width, hight, alfa){};

     double area()
    {
        return ( w * h );
    }
    ~Rectangle(){};
};
class Square : public Parallelogram
{
public:
    Square ( double width = 10, double hight = 0, double alfa = 90)
    : Parallelogram (width, hight, alfa){};

     double area()
    {
        return ( w * w );
    }
    ~Square(){};
};
class Rhombus : public Parallelogram
{
public:
    Rhombus ( double width = 5, double hight = 6, double alfa = 45)
    : Parallelogram (width, hight, alfa){};

     double area()
    {
        return ( w * h * sin(a));
    }
    ~Rhombus(){};
};
class Circle : public Figure
{
public:
    Circle (double width = 1, double hight = 0, double alfa = 0)
    : Figure (width, hight, alfa){};

     double area()
    {
        return ( w * w * 3.14159);
    }
    ~Circle(){}
};

//============================================================================================================
/*2. Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.
*/
//============================================================================================================

class Car
{
protected:
    string c_company;
    string c_model;
public:
    Car ( string model, string company) { c_model = model; c_company = company;}
    virtual void carinfo (){};
    virtual ~Car(){}
};
class PasangerCar : virtual public Car
{
public:
    PasangerCar ( string model, string company)
    : Car ( model,  company) {cout << "PasangerCar constructor "<< endl;}

    void carinfo (string model, string company)
    {
        cout << "Model: " << model << ". Company: " << company << "." << endl;
    }
    ~PasangerCar(){}
};

class Bus : virtual public Car
{
public:
    Bus ( string model, string company)
    : Car ( model,  company) {cout << "Bus constructor " << endl;}

    void carinfo (string model, string company)
    {
         cout << "Model: " << model << ". Company: " << company << "." << endl;
    }
    ~Bus(){}
};
class Minivan : public Bus, public PasangerCar
{
public:
    Minivan ( string model, string company)
    : Car ( model,  company), Bus ( model,  company), PasangerCar ( model,  company)
    {cout << "Minivan constructor " << endl;}

    void carinfo (string model, string company)
    {
       cout << "Model: " << model << ". Company: " << company << "." << endl;
    }
    ~Minivan(){}
};
//============================================================================================================

//============================================================================================================
/*3. Реализовать класс Hand, который представляет собой коллекцию карт.
В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив,
а тип его элементов должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
• метод Add, который добавляет в коллекцию карт новую карту,
соответственно он принимает в качестве параметра указатель на новую карту
• метод Clear, который очищает руку от карт
• метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).*/
//============================================================================================================

class Fraction
{
  double num;
  double den;
public:
    Fraction() {}
    Fraction (double n , double d) : num (n), den (d) {}

    double fraction ()
    {
        if (den != 0)
        {
            return ( num / den );
        }
        else
        {
            cout << "Unacceptable action! The denominator cannot be = 0" <<endl;
            return 0;
        }

    }
    ~Fraction(){}
    friend Fraction operator + (const Fraction &c1, const Fraction &c2);
    friend Fraction operator - (const Fraction &c1, const Fraction &c2);
    friend Fraction operator / (const Fraction &c1, const Fraction &c2);
    friend Fraction operator * (const Fraction &c1, const Fraction &c2);
    friend Fraction operator - (const Fraction &c1);
    friend Fraction operator == (const Fraction &c1, const Fraction &c2);
    friend Fraction operator > (const Fraction &c1, const Fraction &c2);
};
//============================================================================================================
Fraction operator > (const Fraction &f1, const Fraction &f2)
{
  Fraction temp;
  temp.num = f1.num > f2.num;
  temp.den = f1.den > f2.den;
  return(temp);
}

Fraction operator == (const Fraction &f1, const Fraction &f2)
{
  Fraction temp;
  temp.num = f1.num == f2.num;
  temp.den = f1.den == f2.den;
  return(temp);
}

Fraction operator - (const Fraction &c1)
{
  Fraction temp;
  temp.num = temp.num * (-1);
  temp.den = temp.den;
  return(temp);
}

Fraction operator + (const Fraction &f1, const Fraction &f2)
{
  Fraction temp;
  temp.num = f1.num + f2.num;
  temp.den = f1.den + f2.den;
  return(temp);
}
Fraction operator - (const Fraction &f1, const Fraction &f2)
{
  Fraction temp;
  temp.num = f1.num - f2.num;
  temp.den = f1.den - f2.den;
  return(temp);
}
Fraction operator / (const Fraction &f1, const Fraction &f2)
{
  Fraction temp;
  temp.num = f1.num / f2.num;
  temp.den = f1.den / f2.den;
  return(temp);
}
Fraction operator * (const Fraction &f1, const Fraction &f2)
{
  Fraction temp;
  temp.num = f1.num * f2.num;
  temp.den = f1.den * f2.den;
  return(temp);
}

//============================================================================================================
/*4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три
поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля
масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом
классе должно быть два метода:
● метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он
ее поворачивает лицом вверх, и наоборот.
● метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.*/
//============================================================================================================

class Card
{
public:
enum class e_suit { Diamonds = 'D', Hearts = 'H', Clubs = 'C', Spades = 'S' };
enum class e_value  { two = 2,three = 3,four = 4,five = 5,six = 6,seven = 7,eight =8,
                      nine =9,ten =10,Jack = 10,Queen = 10,King = 10,Ace = 1};
//============================================================================================================

e_suit c_suit;
e_value c_value;
bool c_upPosition = 0;
    Card (){}
    Card (e_suit suit , e_value value, bool upPosition) : c_suit(suit), c_value(value), c_upPosition(upPosition){}
    void Flip()
    {
        c_upPosition = !c_upPosition;
    };
    e_value GetValue()
    {
        //cout << " ' "<< static_cast <char> (c_suit) << " ' ";
        //cout << static_cast <int> (c_value) << " ' " <<  c_upPosition << " ' " << endl;
        return c_value;
    };

};
//============================================================================================================

int main()
{
//============================================================================================================
    cout << " Task 1: Figure " << endl;
    cout << endl;
    Parallelogram p;
    p.area();
    Rectangle r;
    r.area();
    Square s;
    s.area();
    Rhombus rh;
    rh.area();
    Circle c;
    c.area();
    cout << " Parallelogram area: " <<  p.area() << ". Rectangle area: " <<  r.area() << ". Square area: " <<  s.area() <<endl;
    cout << " Rhombus area: " <<  rh.area() << ". Circle area: " <<  c.area() <<endl;
    cout << endl;
//============================================================================================================
    cout << " Task 2: Cars " << endl;
    cout << endl;

    PasangerCar p_car ("Model S", "Tesla");
    Bus b_car ("312", "Maz");
    Minivan m_car ("Caravan", "Dodge");
    m_car.carinfo("Caravan", "Dodge");



    cout << endl;
//============================================================================================================
    cout << " Task 3: Fraction " << endl;
    cout << endl;

    Fraction a ( 3, 7), b ( 9, 2);
    a.fraction ();
    b.fraction ();
    Fraction a1;
    Fraction a2;
    Fraction a3;
    Fraction a4;
    Fraction a5;
    Fraction a6;    `
    Fraction a7;
    a1 = a + b;
    a2 = a - b;
    a3 = a / b;
    a4 = a * b;
    a5 = -a;
    a6 = a == b;
    a7 = a > b;
    a1.fraction();
    cout << " += "  << a1.fraction()<< endl;
    a2.fraction();
    cout << " -= " << a2.fraction()<< endl;
    a3.fraction();
    cout << " /= " << a3.fraction() << endl;
    a4.fraction();
    cout << " *= "  << a4.fraction()<< endl;
    a5.fraction();
    cout << " - "  << a5.fraction()<< endl;
    a6.fraction();
    cout << " - "  << a6.fraction()<< endl;
    a7.fraction();
    cout << " > "  << a7.fraction()<< endl;

    cout << endl;
//============================================================================================================
    cout << " Task 4: Card " << endl;
    cout << endl;

    Card ace (Card::e_suit::Diamonds,Card::e_value::King,0);
    ace.GetValue();
    ace.Flip();//проверка переворота
    ace.GetValue();
    cout << " Card value = " << static_cast <int> (ace.GetValue()) << endl;

    return 0;
}
*/
