#pragma once

#include <windows.h>

#include "vartypes.h"

class Cfile32
{
public:
    HANDLE handle();
    void attach(HANDLE handle);
    void detach();
    int open(const xcc_string& name, dword access);
    int open(const xcc_string& name, dword access, dword creation, dword share);
    int open_read(const xcc_string& name);
    int open_edit(const xcc_string& name);
    int open_write(const xcc_string& name);
    int get_size() const;
    FILETIME get_creation_time() const;
    FILETIME get_last_access_time() const;
    FILETIME get_last_write_time() const;
    int read(void* data, int size);
    int read_line(xcc_string& s);
    int write(const void* data, int size);
    int write(int v);
    int write(const xcc_string& s);
    int set_eof();
    void close() JMP_THIS(0x531E90);
    Cfile32();
    virtual ~Cfile32();

    bool eof() const
    {
        return m_p >= get_size();
    }

    bool is_open() const
    {
        return m_is_open;
    }

    int get_p() const
    {
        return m_p;
    }

    void seek(int p)
    {
        m_p = p;
    }

    void skip(int p)
    {
        m_p += p;
    }
private:
    HANDLE m_handle;
    bool m_is_open;
    int m_p;
};

int file32_write(const xcc_string& name, const void* s, int cb_s);