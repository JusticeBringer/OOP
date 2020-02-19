class Set{
    protected:
        int *array;
        unsigned size;

    public:
        Set ();
        Set (int*, unsigned);
        Set (const Set &ob);
        ~Set ();

        int  cautare (int );
        void insert (int );
        void afisare ( );
        void stergere (int );
        int sumElements ();
        int* nrPare   (unsigned *size );
        int* nrImpare (unsigned *size);
        int nrElem ();
        void swap(int *a, int* b);
        void sort ( );

        friend std::ostream & operator << (std::ostream &out, const Set &c);
        friend std::istream & operator >> (std::istream &input,  Set &c);
        Set operator = (Set c);
        int&  operator [] (int i);
        Set operator + (const Set &ob);
        bool operator < (const Set &ob);
        bool operator > (const Set &ob);
        int* operator * (int value);
};