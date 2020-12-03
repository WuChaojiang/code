_Pragma("once")

class HasPtrMem
{
public:
    HasPtrMem();
    HasPtrMem(const HasPtrMem &h);
    HasPtrMem(HasPtrMem &&h);
    ~HasPtrMem();

    int *d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mvtr;
};

HasPtrMem GetTemp();
void JudgeReferenceType();
// #endif // HAS_PTR_MEM