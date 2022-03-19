#include <iostream>
#include <string>

using namespace std;

//! Інкапсуляція

class Human
{
public:
    int age;
    int weight;
    string name;

    void Print()
    {
        cout << "Name " << name << endl;
        cout << "Age " << age << endl;
        cout << "Weight " << weight<< endl;
    }
};

void HumanInfo1()//! 1 урок
{
    Human firstHuman;
    firstHuman.age = 35;
    firstHuman.name = "Pavlo";
    firstHuman.weight = 100;

    cout << firstHuman.name << endl;
    cout << firstHuman.weight << endl;

    Human secondHuman;
    secondHuman.age = 20;
    secondHuman.name = "Dodik";

    cout << firstHuman.age+secondHuman.age << endl;
}

void HumanInfo2()//! 2 урок
{
    Human firstHuman;

    firstHuman.age = 30;
    firstHuman.name = "Ivan";
    firstHuman.weight = 60;

    firstHuman.Print();
}

class Point1
{
public:
//private:
// protected:
    int x;
    int y;
    int z;
};

class Point2
{
public:
    int x;
    int y;
    void Print()
    {
        cout << "x= " << x << endl;
        cout << "y= " << y << endl;
        PrintZ();
    }
private:
    int z;
    void PrintZ()
    {
        cout << "PrintZ" << endl;
        cout << "z= " << z << endl;
    }
};

void PointXY()//! 1 урок
{
    Point2 a;
    a.x = 1;
    a.y = 4;
    //a.z = 5;
    a.Print();
}

class Point3 //! приклад інкапсуляції: доступ до х у хоча вони у private
{
private:
    int x;
    int y;

public:

    // Point3() //! конструктор класу за замочуванням
    // {

    // }

    Point3() //! конструктор класу
    {
        x=0;
        y=0;
    }

    Point3(int x, int y) //! конструктор класy з параметрами
    {
        this->x=x;
        this->y=y;
    }

    Point3(int a, int b,int c,int d) 
    {
        this->x=a+b;
        this->y=c+d;
    }

    // ~Point3() //! декструктор (тільки один)
    // {
        
    // }

    bool operator ==(const Point3 &other)
    {
        return this->x == other.x && this->y == other.y;
    }

    bool operator !=(const Point3 &other)
    {
        return this->x != other.x && this->y != other.y;
    }

    Point3 &operator ++()
    {
        this->x++;
        this->y++;

        return *this;
    }

    Point3 &operator ++(int value)
    {
        Point3 temp(*this);

        this->x++;
        this->y++;

        return temp;
    }

     Point3 &operator --(int value)
    {
        Point3 temp(*this);

        this->x--;
        this->y--;

        return temp;
    }

    Point3 &operator --()
    {
        this->x--;
        this->y--;

        return *this;
    }

    int GetX()
    {
        return x;
    }

    void SetX(int x)
    {
        this->x = x;
    }

    int GetY()
    {
        return y;
    }

    void SetY(int valueY)
    {
        y = valueY;
    }

    void Print ()
    {
        cout << "x= " << x << endl;
        cout << "y= " << y << endl;
    }
};

void PointXY3()
{
    Point3 a(5,4);
    Point3 b(5,4);

    a++;
    a.Print();

    //bool result = a==b;
}

class MyClass
{
public:
    int *data;

    MyClass(int size) //! конструктор
    {
        this->Size = size; 
        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }
        
        cout << "Construcktor " << this << endl;
    }

    ~MyClass() //! деструктор
    {
        cout << "Destrucktor " << this << endl;
        delete[] data;
    } 

    MyClass(const MyClass &other) //! конструктор копіювання
    {
        this->Size = other.Size;
        this->data = new int[other.Size];
        for (int i = 0; i < Size; i++)
        {
            this->data[i] = other.data[i];
        }
        
        cout << "Copy Construcktor " << this << endl;
    }

    MyClass & operator = (const MyClass &other) //! перегрузка оператора = 
    {
        cout << "Operator = " << this << endl;

        this->Size = other.Size;

        if(this->data!=nullptr)
        {
            delete[] data;
        }

        for (int i = 0; i < Size; i++)
        {
            this->data[i] = other.data[i];
        }

        return *this;
    }

private:
    int Size;
};  

void Foo1(MyClass *value)
{
    cout << "Function FOO_1" << endl;
}

MyClass Foo2()
{
    cout << "Function FOO_2" << endl;
    MyClass temp(2);
    return temp;
}

void Class()
{
    MyClass a(5);
    MyClass b(10);
    a = b;
    //a.operator=(b);

}

class CoffeeGrinder//! приклад інкапсуляції
{
private:
    bool CheckVoltage()
    {
        return false;
    }

public:
    void Start()
    {
        if(CheckVoltage())
            cout << "Vjuhhh" << endl;
        else
            cout << "Beep beep" << endl;
    }
};

//! Наслідування

class Man
{
private:
    string name;
public:
    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    void Print()
    {
        cout << "Name: " << name << endl;
    }
};

class Student : public Man
{
public:
    string group;

    void learn()
    {
        cout << "I'm studying" << endl;
    }
};

class ExtramuralStudent : public Student
{
public:
    void learn()
    {
        cout << "I visit university very rarely" << endl;
    }
};

class Professor : public Man
{
public:
    string subject;
};

void Man()
{
    Student st;
    st.setName("pavlo");
    string n = st.getName();
    cout << n << endl;

    ExtramuralStudent extraSt;
    extraSt.setName("Dodik");
    cout << extraSt.getName() << endl;
}

class Car
{
private:
    int electronics;
    int engine;

public:
    int volumeOfEmgine;
    int length;

    void Start()
    {
        cout << "Car's starting engine" << endl;
    }

    void SetLength(int l)
    {
        length = l;
    }
};

class BMW : protected Car
{
private:
    int engine;
public:
    int clearance;
    int sizeOfTyres;
    
    void Size()
    {
        length = 15;
    }
};

class M5 : public BMW
{
public:
    void SetSize()
    {
        length = 15;
    }
};

void DriveCar()
{
    BMW m3;
    m3.clearance = 15;
    m3.sizeOfTyres = 30;
}

class A
{
public:
    string msgOne = "Message one";
    void Print();
    // {
    //     cout << "Message" << endl;
    // }
private:
    string msgTwo = "Message two";
protected:
    string msgThree = "Message three";

// public:
//     string GetMsgTwo()
//     {
//         return msgTwo;
//     }
};

void A::Print()
{  
    cout << "Message" << endl;
}

class B : public A
{

public:

    void PrintMsg()
    {
        cout << msgOne << endl;
        // cout << GetMsgTwo() << endl;
        // cout << msgThree << endl;
    }
    
};

//! Множинне наслідування

class Automobile
{
public:
    string nameCar = "Car";
    void drive()
    {
        cout << "I'm driving" << endl;
    }
};

class Airplane
{
public:
    string namePlane = "Plane";
    void fly()
    {
        cout << "I'm flying" << endl;
    }
};

class FlyingCar : public Automobile,public Airplane
{

};

void Move()
{
    Automobile a;
    Airplane b;
    // a.drive();
    // b.fly();

    FlyingCar fc;
    fc.drive();
    fc.fly();
    cout << fc.nameCar << endl;
}

//! ромбовидне наслідування

class NameDetail
{
public:
    NameDetail()
    {
        cout << "NameDetail" << endl;
    }
};

class Monitor : public NameDetail
{
public:
    Monitor()
    {
        cout << "Monitor" << endl;
    }
};

class SystemBlock : public NameDetail
{
public:
    SystemBlock()
    {
        cout << "SystemBlock" << endl;
    }
};

class PC : public Monitor, public SystemBlock
{
public:
    PC()
    {
        cout << "PC" << endl;
    }
};

void StartPC()
{
    PC acer;
}

class Game 
{
public:
    void Start()
    {
        cout << "Game's starting" << endl;
    }

    void End()
    {
        cout << "Game's ending" << endl;
    }

    int setNum()
    {
        return num;
    }

protected:
    string rules;
private:
    int num;
};

class Football:public Game
{
public:
    void SetRule()
    {
        rules = "nbkjfb";
        //num = 15;
        Start();
        End();
    }
};

//! поліморфізм

class Gun
{
public:
    virtual void Shoot()
    {
        cout << "BANG!" << endl;
    }
};

class SubmachineGun : public Gun
{
public:
    void Shoot() override
    {
        cout << "BANG! BANG! BANG!" << endl;
    }
};

class Bazooka :public Gun
{
public:
    void Shoot() override
    {
        cout << "BADABUB" << endl;
    }
};

class Player
{
public:
    void Shoot(Gun *gun )
    {
        gun->Shoot();
    }
};

void UseGun()
{
    //Gun gun;
    SubmachineGun subgun;
    //Gun *point = &subgun;

    Player player;
    player.Shoot(&subgun);
}

//! абстрактний клас чисто віртуальна функція

class Weapon //! абстрактний клас неможливо створити обєкт класу
{
public:
    virtual void Shoot() = 0;
};

class Gun1:public Weapon
{
public:
    virtual void Shoot()
    {
        cout << "BANG!" << endl;
    }
};


class SubmachineGun1 : public Gun1
{
public:
    void Shoot() override
    {
        cout << "BANG! BANG! BANG!" << endl;
    }
};

class Bazooka1 :public Weapon
{
public:
    void Shoot() override
    {
        cout << "BADABUB" << endl;
    }
};

class Knife:public Weapon
{
public:
    void Shoot() override
    {
        cout << "Vjuh" << endl;
    }
};

class Player1
{
public:
    void Shoot(Weapon *weapon )
    {
        weapon->Shoot();
    }
};

void UseGun1()
{
    Player1 player1;
    Knife knife;

    player1.Shoot(&knife);
}



int main()
{
    cout.setf(ios::boolalpha);
    //WorkCoffeeGrinder();
    //Man();
    //DriveCar();
    //Move();
    //StartPC();
    // UseGun();
    //PointXY3();
    //Class();

    UseGun1();

    return 0;
}
