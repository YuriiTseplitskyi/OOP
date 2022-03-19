#include <iostream>
 
using namespace std;

class Car
{
private:

    bool checkLevelOfOil()
    {
        if(levelOfOil>10)
            return true;
        else
            return false;
    }

    bool checkCarburetor()
    {
        return carburetor;
    }

public:
    
    string name;
    double length;
    double clearence;
    double sizeOftyres;

    void setLevelOfOil(int l)
    {
        levelOfOil = l;
    }

    void move()
    {
        cout << "Vehicle's riding" << endl;
    }
    
    void StartEngine()
    {
        if(checkLevelOfOil() && checkCarburetor())
            cout << "Car's starting a movement" << endl;
        else
            cout << "Car requires repair" << endl;
    }

protected:

    bool engine;
    bool carburetor = true;
    bool pendant = true;
    int levelOfOil;
    int electronics;
    int volumeOfEngine;

};

class Airplane
{
public:
    void move()
    {
        cout << "Vehicle's flying" << endl;
    }
};

class Boat
{
public:
    void move()
    {
        cout << "Vehicle's sailing" << endl;
    }
};

class Hybrid : public Car,public Airplane,public Boat
{

};

void HybridMove()
{
    Hybrid vehicle;

    ((Car)vehicle).move();
    ((Airplane)vehicle).move();
    ((Boat)vehicle).move();

    vehicle.length = 15;
}

class BMW: public Car
{
private:

    bool checkPendant()
    {
        if(pendant) 
            return true;
        else 
            return false;
    }

public:
    void LaunchStart()
    {
        if(checkPendant())
        {
            StartEngine();
        }
    }

    void SetDafaultSize()
    {
        length=15;
        clearence = 20;
    }

protected:

    void ModifyElectroncis()
    {
        electronics = 15;
    }

    void ModifyEngine()
    {
        engine = true;
        sizeOftyres = 20;
    }
};

void DriveCar()
{
    int level;
    BMW m3;
    cout << "Level= ";cin>>level;
    m3.setLevelOfOil(level);
    m3.LaunchStart();
}

class Auto
{
private:
    bool checkCarburetor()
    {
        return carburetor;
    }
public:
    virtual void Move()
    {
        if(checkCarburetor())
            cout << "Vehicle is moving" << endl;
    }
protected:
    bool carburetor = true;
};

class Tesla : public Auto
{
private:
    bool checkEllectronics()
    {
        return electronics;
    }
public:
    void Move() override
    {
        if(checkEllectronics())
            Auto::Move();
            //cout << "Vehicle is moving silently" << endl;
    }
protected:
    bool electronics = true;
};

class Driver
{
public:
    void Drive(Auto *car)
    {
        car->Move();
    }
};

void DriveAuto()
{ 
    Driver driver;
    Auto car;
    Tesla tesla;

    driver.Drive(&car);
    driver.Drive(&tesla);
}

class Point 
{
private:
    int x;
    int y;

public:

    Point() 
    {
        x=0;
        y=0;
    }

    Point(int x, int y) 
    {
        this->x=x;
        this->y=y;
    }

    bool operator ==(const Point &other)
    {
        return this->x == other.x && this->y == other.y;
    }

    bool operator !=(const Point &other)
    {
        return this->x != other.x && this->y != other.y;
    }

    Point &operator ++()
    {
        this->x++;
        this->y++;

        return *this;
    }

    Point operator ++(int value)
    {
        Point temp(*this);

        this->x++;
        this->y++;

        return temp;
    }

     Point operator --(int value)
    {
        Point temp(*this);

        this->x--;
        this->y--;

        return temp;
    }

    Point &operator --()
    {
        this->x--;
        this->y--;

        return *this;
    }

    Point &operator =(const Point &other)
    {
        this->x = other.x;
        this->y = other.y;

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

    void SetY(int y)
    {
        this->y = y;
    }

    void Print ()
    {
        cout << "x= " << x << endl;
        cout << "y= " << y << endl;
    }
};

void PointXY()
{
    Point a(5,4);
    cout << "A" << endl;
    a.Print();
    Point b=a++;
    cout << "B" << endl;
    b.Print();
    cout << "A" << endl;
    a.Print();

    //a = b;
    //a++;
    //bool result = a==b;
}

class Game
{
public:
    virtual void StartGame() = 0;
};

class Football:public Game
{
public:
    void StartGame() override
    {
        cout << "There is a whistle, players kick the ball" << endl;
    }
};

class Basketball:public Game
{
public:
    void StartGame() override
    {
        cout << "There is a whistle, players struggle for the ball with hands" << endl;
    }
};

class Referee 
{
public:
    void StartGame(Game *game) 
    {
        game->StartGame();
    }
};

void StartGame()
{
    Referee referee;
    Football football;

    referee.StartGame(&football);
}
int main()
{
    //DriveCar();
    //HybridMove();
    //DriveAuto();
    //PointXY();
    StartGame();
}