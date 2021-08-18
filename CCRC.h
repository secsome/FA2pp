class basic_string
{
public:
    char allocator;
    char* _Ptr;
    unsigned int _Len;
    unsigned int _Res;
};

class CCRC
{
public:

    static unsigned int __cdecl GetID(CCRC crc, char allocator, char* _Ptr, unsigned int _Len, unsigned int _Res) { JMP_STD(0x528A40); }

    unsigned int GetID(basic_string& str)
    {
        return GetID(*this, str.allocator, str._Ptr, str._Len, str._Res);
    }

    unsigned int m_crc;
};