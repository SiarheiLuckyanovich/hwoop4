#include "Card.h"
#include <vector>
#include <iostream>
#include <cassert> // для assert()
using namespace std;
//============================================================================================================
/* 1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
• для удаления последнего элемента массива (аналог функции pop_back() в векторах) V
• для удаления первого элемента массива (аналог pop_front() в векторах) V
• для сортировки массива V
• для вывода на экран элементов V.*/
//============================================================================================================

class ArrayInt
{
private:
    int m_length;
    int* m_data;
public:
    ArrayInt(): m_length(0), m_data(nullptr) {}

    ArrayInt(int length): m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
        {
            m_data = new int[length];
        }
        else
        {
            m_data = nullptr;
        }
    }
    ~ArrayInt()
    {
        delete[] m_data;
    }
//============================================================================================================
    void erase()
    {
        delete[] m_data;
        // Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
        m_data = nullptr;
        m_length = 0;
    }
//============================================================================================================
    int getLength() { return m_length; }
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

// Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
//============================================================================================================
    void resize(int newLength)
    {
        // Если массив уже нужной длины — return
        if (newLength == m_length)
        {
            return;
        }
    // Если нужно сделать массив пустым — делаем это и затем return
        if (newLength <= 0)
        {
            erase();
            return;
        }
    // Теперь знаем, что newLength >0
    // Выделяем новый массив
    int *data = new int[newLength];

    // Затем нужно разобраться с количеством копируемых элементов в новый массив
    // Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
    if (m_length > 0) {
      int elementsToCopy = (newLength > m_length) ? m_length : newLength;

      // Поочередно копируем элементы
      for (int index=0; index < elementsToCopy ; ++index) {
        data[index] = m_data[index];
      }
    }

    // Удаляем старый массив, так как он нам уже не нужен
    delete[] m_data;

    // И используем вместо старого массива новый! Обратите внимание, m_data указывает
    // на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
    // данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
    m_data = data;
    m_length = newLength;
  }
//============================================================================================================
void insertBefore(int value, int index)
  {
    // Проверка корректности передаваемого индекса
    assert(index >= 0 && index <= m_length);

    // Создаем новый массив на один элемент больше старого массива
    int* data = new int[m_length+1];

    // Копируем все элементы до index-а
    for (int before=0; before < index; ++before) {
      data[before] = m_data[before];
    }

    // Вставляем новый элемент в новый массив
    data [index] = value;

    // Копируем все значения после вставляемого элемента
    for (int after=index; after < m_length; ++after) {
      data[after+1] = m_data[after];
    }

    // Удаляем старый массив и используем вместо него новый
    delete[] m_data;
    m_data = data;
    ++m_length;
  }
//============================================================================================================
// 1.1/
void deleteLast () //метод для удаления последнего элемента массива (аналог функции pop_back() в векторах)
  {
    // Создаем новый массив на один элемент меньше старого массива
    int* data = new int[m_length-1];

    // Копируем все элементы до m_length-1
    for (int before=0; before < m_length-1; ++before) {
      data[before] = m_data[before];
    }
    // Удаляем старый массив и используем вместо него новый
    delete[] m_data;
    m_data = data;
    --m_length;
  }

//============================================================================================================
// 1.2/
void deleteFirst () //метод для удаления для удаления первого элемента массива (аналог pop_front() в векторах)
  {
    // Создаем новый массив на один элемент меньше старого массива
    int* data = new int[m_length-1];

    // Копируем все элементы от 1го(0+1) до m_length
    for (int before=1; before < m_length; ++before) {
      data[before-1] = m_data[before];
    }
    // Удаляем старый массив и используем вместо него новый
    delete[] m_data;
    m_data = data;
    --m_length;
  }

//============================================================================================================
// 1.3 метод для сортировки массива.

//Код сортировки из 7го ДЗ по основам с++
void SwapArrayInt()
{
    for (int i = 0U; i < m_length; i++)
    {
        bool flag = true;
        for (int j = 0U; j < m_length - (i + 1); j++)
            {
                if (m_data[j] > m_data[j + 1])
                {
                    flag = false;
                    swap (m_data[j], m_data[j + 1]);
                }
            }
        if (flag)
        break;
    }
}

//============================================================================================================
// 1.4 метод для вывода на экран элементов.

void printArrayInt()
{
    for (int i = 0U; i < m_length; i++)
    {
        cout << " " << m_data[i] << " " ;
    }
    cout << endl;
}

  void push_back(int value) { insertBefore(value, m_length); }
};
//============================================================================================================
/* 2. Дан вектор чисел, требуется выяснить, сколько среди них различных.
Постараться использовать максимально быстрый алгоритм.*/
//============================================================================================================

void printVector(vector<int> &a)
{
    vector<int>::iterator it;       // объявляем итератор
    it = a.begin();          // присваиваем ему начало вектора
    while (it != a.end())    // пока итератор не достигнет конца
    {
        cout << *it << " ";         // выводим значение элемента, на который указывает итератор
        ++it;                       // и переходим к следующему элементу
    }
}
int checkVectorArrayInt(vector<int> &a)
{
    vector<int>b;
    size_t n = 0;
    vector<int>::iterator it;
    it = a.begin();
    b.assign( a.begin(), a.end());

    if (a.size()>0)
    {
        for (size_t i = 0U; i < a.size(); ++i)
        {
            for (size_t j = i+1; j < a.size(); ++j)
            {
                if (a[i] == a[j])
                {
                    a.erase(it +j);
                    j--;
                }
            }
        } n = a.size();
    }a.assign( b.begin(), b.end());;
    return n;
}

//============================================================================================================
/* 3. Реализовать класс Hand, который представляет собой коллекцию карт.
В классе будет одно поле: вектор указателей карт (удобно использовать вектор,
т.к. это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card).
Также в классе Hand должно быть 3 метода:
• метод Add, который добавляет в коллекцию карт новую карту,
соответственно он принимает в качестве параметра указатель на новую карту
• метод Clear, который очищает руку от карт
• метод GetValue, который возвращает сумму очков карт руки
(здесь предусмотреть возможность того, что туз может быть равен 11). V*/
//============================================================================================================

class Hand
{
public:
vector <Card*>  m_Cards;

    Hand (){}
    Hand (vector <Card*>  m_Cards) {}

    void Add (Card* pCard)
    {
        m_Cards.push_back(pCard);
    }

    void Clear ()
    {
        m_Cards.clear();
    }
//============================================================================================================
    int GetValue ()
    {
        int vsum=0;
        for (size_t i=0; i<m_Cards.size(); i++)
        {
            if (vsum < 21)
            {
                if ((static_cast <int> (m_Cards[i] -> c_value)) != 1)
                {
                    vsum += (static_cast <int> (m_Cards[i] -> c_value));
                }
                else if ((vsum + 10)>21)
                    {
                        vsum += (static_cast <int> (m_Cards[i] -> c_value));
                    }
                    else vsum += 10;
            } else vsum += (static_cast <int> (m_Cards[i] -> c_value));
        }
        cout <<  vsum << " - sum " << endl;

        return  vsum;
    }
//============================================================================================================
    void printHand()
    {
        for (size_t i=0; i<m_Cards.size(); i++)
        {
            cout << " ' "<< static_cast <char> (m_Cards[i] ->c_suit) << " ' ";
            cout << static_cast <int> (m_Cards[i] ->c_value) << " ' ";
            cout <<  m_Cards[i] ->c_upPosition << " ' " << endl;
        }
    }
};
//============================================================================================================





int main(int argc, char* argv[])
{
//============================================================================================================
    cout << "1st task: Conteiner" << endl;

    ArrayInt arrayInt;
    arrayInt.push_back(100);
    arrayInt.push_back(0);
    arrayInt.push_back(1);
    arrayInt.push_back(11);
    arrayInt.push_back(10);
    arrayInt.insertBefore(10, 3);
    arrayInt.push_back(15);
    arrayInt.push_back(10);
    arrayInt.push_back(11);
    arrayInt.push_back(10);
    arrayInt.printArrayInt();
    cout << arrayInt.getLength() << "is Length" << endl;
    arrayInt.SwapArrayInt();
    arrayInt.printArrayInt();
    arrayInt.deleteFirst();
    arrayInt.printArrayInt();
    arrayInt.deleteLast();
    arrayInt.printArrayInt();
    arrayInt.push_back(11);
    arrayInt.printArrayInt();

    cout << endl;

//============================================================================================================
    cout << "2st task: vector check" << endl;
    cout << endl;

vector<int> myVector;
    for (int count=0; count < 10; ++count)
    myVector.push_back(count);
    myVector[3] =9;
    myVector[5] =1;
    myVector[4] =9;
    myVector[6] =1;
    printVector(myVector);
cout << endl;
cout << "different elements = " << checkVectorArrayInt(myVector) << endl;
printVector(myVector);
cout << endl;
cout << endl;
//============================================================================================================
    cout << "3st task: Hand " << endl;
    cout << endl;

    Card ace (Card::e_suit::Diamonds,Card::e_value::Ace,0);
    Card king (Card::e_suit::Diamonds,Card::e_value::King,0);
    Card six (Card::e_suit::Diamonds,Card::e_value::six,0);
    Hand h;

    h.Add(&king);
    h.GetValue();
    h.Add(&six);
    h.GetValue();
    h.Add(&ace);
    h.GetValue();
    cout << "Hand value sum = " << h.GetValue() << endl;
    h.printHand();
    h.Clear();
    h.Add(&king);
    h.GetValue();
    h.printHand();


  return 0;
}
