#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <typeinfo>

using namespace std;

class Abonament
{
protected:
    string nume_abonament;
    float pret;
    int perioada;

public:
    Abonament(int perioada = 0, string nume_abonament = "nume necunoscut", float pret = 0)

    {
        this->perioada = perioada;
        this->nume_abonament = nume_abonament;
        pret = 0;
    }

    Abonament(string nume_abonament, float pret, int perioada)
    {
        nume_abonament = nume_abonament;
        pret = pret;
        perioada = perioada;
    }

    Abonament(const Abonament& obj)
    {
        nume_abonament = obj.nume_abonament;
        pret = obj.pret;
        perioada = obj.perioada;
    }

    virtual ~Abonament() {}

    void operator=(const Abonament& obj)
    {
        pret = obj.pret;
        nume_abonament = obj.nume_abonament;
        perioada = obj.perioada;
    }

    virtual void afisare()
    {
        cout << endl;
        cout << "Date abonament:\n";
        cout << "Nume: " << nume_abonament << endl;
        cout << "Pret: " << pret << endl;
        cout << "Perioada (luni): " << perioada;
    }

    virtual float suma_incasata()
    {
        return pret * perioada;
    }


    void setPret(float pret)
    {
        this->pret = pret;
    }

    float getPret()
    {
        return pret;
    }

    void setNumeAbonament(string nume_abonament)
    {
        this->nume_abonament = nume_abonament;
    }

    string getNumeAbonament()
    {
        return nume_abonament;
    }

    void setPerioada(int perioada)
    {
        this->perioada = perioada;
    }

    int getPerioada()
    {
        return perioada;
    }

    virtual void setReducere(int reducere) {}
    virtual int getReducere()
    {
        return 0;
    }

    void reducereNoua(float x)
    {
        pret = ((100 - (float)x) / 100);
    }

    friend istream& operator>>(istream&, Abonament&);
    friend ostream& operator<<(ostream&, Abonament&);
    friend class Abonat;
};
istream& operator>>(istream& in, Abonament& obj)
{
    cout << "Date abonament:\n";
    cout << "Nume: ";
    in >> obj.nume_abonament;
    try
    {
        cout << "Pret: ";

        if (!(in >> obj.pret))
            throw 1;
        cout << "Perioada (in luni): ";

        if (!(in >> obj.perioada))
            throw 2;
    }
    catch (int x)
    {
        if (x == 1)
            cout << endl << "Pretul trebuie format din cifre." << endl;
        if (x == 2)
            cout << endl << "Perioada trebuie formata din cifre." << endl;
    }
    return in;
}
ostream& operator<<(ostream& out, Abonament& obj)
{
    out << endl;
    out << "Date abonament\n";
    out << "Nume: " << obj.nume_abonament << endl;
    out << "Pret: " << obj.pret << endl;
    out << "Perioada: " << obj.perioada;

    if (obj.perioada == 1)
        out << " luna" << endl;
    else
        out << " luni" << endl;

    return out;
}

class Abonament_Premium : public Abonament
{
    int reducere;
    static int nr_AbonamentePremium;

public:

    Abonament_Premium() : Abonament()
    {
        reducere = 0;
        nr_AbonamentePremium++;
    }

    Abonament_Premium(string nume_abonament, float pret, int perioada, int reducere) : Abonament(nume_abonament, pret, perioada), reducere(reducere)
    {
        nr_AbonamentePremium++;
    }

    Abonament_Premium(const Abonament_Premium& obj) : Abonament(obj)
    {
        reducere = obj.reducere;
        nr_AbonamentePremium++;
    }

    ~Abonament_Premium() {};

    void operator=(const Abonament_Premium& obj)
    {
        Abonament::operator=(obj);
        reducere = obj.reducere;
    }

    void afisare()
    {
        Abonament::afisare();
        cout << "Reducere: " << reducere << "%" << endl;
    }

    float suma_incasata()
    {
        float x;
        x = pret * ((100 - (float)reducere) / 100) * perioada;
        return x;
    }


    void setReducere(int reducere)
    {
        this->reducere = reducere;
    }
    int getReducere()
    {
        return reducere;
    }
    static void afisare_premium()
    {
        if (nr_AbonamentePremium == 1)
            cout << endl << "Un client are abonament premium." << endl;
        else if (nr_AbonamentePremium)
            cout << endl << nr_AbonamentePremium << " au abonamente premium." << endl;
        else
            cout << endl << "Niciun client nu are abonament premium. ";
    }

    friend istream& operator>>(istream&, Abonament_Premium&);
    friend ostream& operator<<(ostream&, Abonament_Premium&);
};
int Abonament_Premium::nr_AbonamentePremium = 0;
istream& operator>>(istream& in, Abonament_Premium& obj)
{
    in >> (Abonament&)obj;
    cout << "Introduceti reducerea (procente): ";

    try
    {
        if (!(in >> obj.reducere))
            throw obj.reducere;
    }
    catch (int x)
    {
        cout << endl << "Reducerea trebuie introdusa in cifre." << endl;
    }

    return in;
}
ostream& operator<<(ostream& out, Abonament_Premium& obj)
{
    out << (Abonament&)obj;
    out << "Reducere: " << obj.reducere << "%" << endl;

    return out;
}

class Persoana
{
protected:
    int id;
    string nume;
    string cnp;

public:

    Persoana()
    {
        id = -1;
        nume = "fara nume";
        cnp = "fara CNP";
    }

    Persoana(int id, string nume)
    {
        id = id;
        nume = nume;
        cnp = "fara CNP";
    }

    Persoana(int id, string nume, string cnp)
    {
        id = id;
        nume = nume;
        cnp = cnp;
    }

    Persoana(const Persoana& P)
    {
        id = P.id;
        nume = P.nume;
        cnp = P.cnp;
    }

    void operator=(const Persoana& obj)
    {
        id = obj.id;
        nume = obj.nume;
        cnp = obj.cnp;
    }

    virtual ~Persoana() {};
    void afisare()
    {
        cout << id << " " << nume << " " << cnp << endl;
    }
    friend istream& operator>>(istream&, Persoana&);
    friend ostream& operator<<(ostream&, Persoana&);
};
istream& operator>>(istream& in, Persoana& obj)
{
    cout << "Date:\n";
    cout << "ID: ";

    try
    {
        if (!(in >> obj.id))
            throw 1;
        cout << "Nume: ";
        in >> obj.nume;
        cout << "CNP: ";
        in >> obj.cnp;
        if ((obj.cnp).size() != 13)
            throw 2;
    }
    catch (int x)
    {
        if (x == 1)
            cout << endl << "ID-ul trebuie format din cifre." << endl;
        else
            cout << endl << "CNP-ul trebuie sa aiba 13 cifre." << endl << endl;
    }

    return in;
}
ostream& operator<<(ostream& out, Persoana& obj)
{
    out << endl;
    out << "ID: " << obj.id << endl;
    out << "Nume: " << obj.nume << endl;
    out << "CNP: " << obj.cnp << endl;

    return out;
}

class Abonat : public Persoana
{
protected:
    string nr_telefon;
    Abonament* x;

public:
    Abonat() : Persoana()
    {
        nr_telefon = "Numar de telefon necunoscut";
        x = new Abonament();
    }
    Abonat(int id, string nume, string nr_telefon) : Persoana(id, nume)
    {
        nr_telefon = nr_telefon;

        int tip_abonament;
        cout << "Introduceti tipul de abonament dorit (1 pentru standard, 2 pentru premium): " << endl;
        if (tip_abonament == 1)
            x = new Abonament();
        else
            x = new Abonament_Premium();
    }
    //???
    Abonat(int id, string nume, string cnp, string nr_telefon) : Persoana(id, nume, cnp)
    {
        nr_telefon = nr_telefon;
        int tip_abonament;
        cout << "Introduceti tipul de abonament dorit (1 pentru standard, 2 pentru premium): " << endl;
        if (tip_abonament == 1)
            x = new Abonament();
        else
            x = new Abonament_Premium();
    }

    Abonat(const Abonat& obj) : Persoana(obj)
    {
        nr_telefon = obj.nr_telefon;
        x = obj.x;
    }

    void operator=(const Abonat& obj)
    {
        Persoana::operator=(obj);
        nr_telefon = obj.nr_telefon;
        x = obj.x;
    }

    ~Abonat() {};
    friend istream& operator>>(istream&, Abonat&);
    friend ostream& operator<<(ostream&, Abonat&);
    friend class Clienti;
};
istream& operator>>(istream& in, Abonat& obj)
{
    in >> (Persoana&)obj;
    cout << "Numar de telefon: ";
    in >> obj.nr_telefon;

    int tip_abonament;
    cout << "Introduceti tipul de abonament dorit (1 pentru standard, 2 pentru premium): " << endl;

    try
    {
        if (!(cin >> tip_abonament))
            throw 1;
    }
    catch (int x)
    {
        cout << endl << "Imposibil de introdus tipul abonamentului." << endl;
    }

    if (tip_abonament == 1)
    {
        obj.x = new Abonament();
        in >> (Abonament&)(*obj.x);
    }
    else
    {
        obj.x = new Abonament_Premium();
        in >> (Abonament_Premium&)(*obj.x);
    }

    return in;
}
ostream& operator<<(ostream& out, Abonat& obj)
{
    out << (Persoana&)obj;
    out << "Numar de telefon: " << obj.nr_telefon;
    if (typeid(*(obj.x)) == typeid(Abonament))
        out << (Abonament&)(*(obj.x));
    else
        out << (Abonament_Premium&)(*(obj.x));
    return out;
}

class Clienti
{
    int nr_persoane;
    Abonat persoane[100];

public:

    Clienti()
    {
        nr_persoane = 0;
    }

    Clienti(int nr)
    {
        nr_persoane = nr;
    }

    Clienti(const Clienti& obj)
    {
        nr_persoane = obj.nr_persoane;
        for (int i = 0; i < nr_persoane; i++)
        {
            persoane[i] = obj.persoane[i];
        }
    }

    void operator=(Clienti& obj)
    {

        nr_persoane = obj.nr_persoane;
        for (int i = 0; i < nr_persoane; i++)
        {
            persoane[i] = obj.persoane[i];
        }
    }

    ~Clienti() { }
    friend istream& operator>>(istream&, Clienti&);
    friend ostream& operator<<(ostream&, Clienti&);

    void SumaIncasata()
    {
        float suma = 0;
        for (int i = 0; i < nr_persoane; i++)
        {
            float suma_incasata;
            suma_incasata = (persoane[i].x)->suma_incasata();
            suma += suma_incasata;
        }
        cout << endl << "Suma incasata este: " << suma << "." << endl;
    }
};
istream& operator>>(istream& in, Clienti& obj)
{
    cout << "Introduceti numarul clientilor\n";
    int i;
    try
    {
        if (!(in >> obj.nr_persoane) || obj.nr_persoane < 0)
            throw 1;
    }
    catch (int x)
    {
        cout << endl << "Imposibil de introdus numarul de clienti. Veti fi scos din aplicatie." << endl << endl;
        getchar();
        exit(EXIT_SUCCESS);
    }

    for (i = 0; i < obj.nr_persoane; i++)
    {
        cout << endl << endl << endl << "Clientul " << i + 1 << ":" << endl;
        in >> obj.persoane[i];
    }

    return in;
}
ostream& operator<<(ostream& out, Clienti& obj)
{
    int i;
    out << "Numar de clienti: " << obj.nr_persoane << endl << endl;
    if (obj.nr_persoane)
    {
        out << "Clientii sunt:" << endl << endl;
        for (i = 0; i < obj.nr_persoane; i++)
        {
            out << "Clientul " << i + 1 << ":";
            out << obj.persoane[i] << '\n';
        }

    }
    else
        out << "Nu sunt clienti de afisat." << endl << endl;
    return out;
}

void Upcasting()
{
    Abonament* ab_standard;
    Abonament_Premium ab_premium;
    ab_standard = &ab_premium;
    ab_standard->reducereNoua(10);
}

void Downcasting()
{
    Abonament* ab_standard;
    Abonament_Premium ab_premium;
    ab_standard = &ab_premium;
    Abonament_Premium* ab_premium2 = (Abonament_Premium*)(ab_standard);
}

void Meniu_Scris()
{
    cout << "Meniu\n";
    cout << "1. Creati o lista noua de clienti (cea veche va fi stearsa)." << endl;
    cout << "2. Vedeti datele clientilor." << endl;
    cout << "3. Afisati numarul clientilor premium." << endl;
    cout << "4. Afisati suma totala incasata din abonamente." << endl;
    cout << "5. Iesiti din program." << endl;
    cout << "Introduceti un numar de la 1 la 5 pentru a alege o optiune (daca nu alegeti un numar, veti fi scos din aplicatie): ";

}

void Meniu()
{
    Meniu_Scris();
    int k = 0;
    int i;
    Clienti persoane;
    cin >> k;
    while (k)
    {
        while (k < 0 || k > 5)
        {
            cin >> k;
            if (k < 0 || k > 5)
                cout << "Va rugam sa introduceti un caracter valid ('1', '2', '3', '4', '5'): ";
        }
        if (k == 1)
        {
            cin >> persoane;
            cout << "Apasati orice tasta pentru a va intoarce la meniu.\n";
            getchar();
            getchar();
            system("CLS");
        }
        if (k == 2)
        {
            cout << persoane;
            cout << endl << "Apasati orice tasta pentru a va intoarce la meniu.\n";
            getchar();
            getchar();
            system("CLS");
        }
        if (k == 3)
        {
            Abonament_Premium::afisare_premium();
            cout << "Apasati orice tasta pentru a va intoarce la meniu.\n";
            getchar();
            getchar();
            system("CLS");
        }
        if (k == 4)
        {
            persoane.SumaIncasata();
            cout << "Apasati orice tasta pentru a va intoarce la meniu.\n ";
            getchar();
            getchar();
            system("CLS");
        }
        if (k == 5)
            exit(EXIT_SUCCESS);
        Meniu_Scris();
        cin >> k;
    }
}

int main()
{
    Meniu();
    return 0;
}