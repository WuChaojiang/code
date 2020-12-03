_Pragma("once");

class HugeMem
{
public:
    HugeMem(int size);
    HugeMem(HugeMem &&rhs);
    ~HugeMem();

    int *c;
    int sz;
};

class Moveable {
    public:
    Moveable();
    Moveable(Moveable &&m);
    ~Moveable();

    
    int *i;
    HugeMem h;
};

Moveable GetMoveableTemp();

struct Maythrow {
Maythrow();
Maythrow(const Maythrow &);
Maythrow(Maythrow &&);
};

struct Nothrow {
    Nothrow();
    Nothrow(Nothrow &&) noexcept;
    Nothrow(const Nothrow &);
};