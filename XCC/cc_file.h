#pragma once

#include "file32.h"

enum t_file_type
{
    ft_ai_ini_ts, ft_ai_ini_ra2, ft_art_ini_ts, ft_art_ini_ra2, ft_aud, ft_avi, ft_bin, ft_bink, ft_bmp, ft_clipboard, ft_cps, ft_csv, ft_dir, ft_drive, ft_fnt, ft_html, ft_hva, ft_ini,
    ft_jpeg, ft_map_dune2, ft_map_td, ft_map_ra, ft_map_ts, ft_map_ts_preview, ft_map_ra2, ft_mix, ft_mng, ft_mp3, ft_mrf,
    ft_ogg, ft_pak, ft_pal, ft_pal_jasc, ft_pcx_single, ft_pcx, ft_png_single, ft_png, ft_pkt_ts, ft_riff, ft_rules_ini_ts, ft_rules_ini_ra2, ft_shp_dune2, ft_shp, ft_shp_ts,
    ft_sound_ini_ts, ft_sound_ini_ra2, ft_st, ft_text, ft_theme_ini_ts, ft_theme_ini_ra2, ft_tmp, ft_tmp_ra, ft_tmp_ts, ft_voc, ft_vpl, ft_vqa, ft_vqp, ft_vxl, ft_wav,
    ft_wav_ima_adpcm, ft_wav_pcm, ft_wsa_dune2, ft_wsa, ft_xcc_lmd, ft_xcc_unknown, ft_xif, ft_zip, ft_unknown, ft_count
};

const char* ft_name[];

class Cmix_file;

class Ccc_file
{
public:
    HANDLE handle();
    int attach(HANDLE handle);
    void detach();
    int open(unsigned int id, Cmix_file& mix_f) JMP_THIS(0x529900);
    int open(const xcc_string& name, Cmix_file& mix_f) JMP_THIS(0x5299C0);
    int open(const xcc_string& name);
    void load(const byte* data, int size);
    void load(const Ccc_file& f);
    t_file_type get_file_type(bool fast = true);
    int read();
    int read(void* data, int size);
    int extract(const xcc_string& name);
    virtual void close() JMP_THIS(0x529D00);
    Ccc_file(bool read_on_open = false) JMP_THIS(0x5298C0);
    ~Ccc_file() JMP_THIS(0x5298F0);

    const byte* get_data() const
    {
        return m_data;
    }

    int get_p() const
    {
        return m_p;
    }

    int get_size() const
    {
        return m_size;
    }

    bool is_attached() const
    {
        return m_attached;
    }

    bool is_open() const
    {
        return m_is_open;
    }

    void seek(int p)
    {
        m_p = p;
    }

    void skip(int p)
    {
        m_p += p;
    }

    virtual int post_open()
    {
        return 0;
    }
protected:
    bool m_data_loaded;
private:
    void clean_up();

    bool m_attached;
    byte* m_data;
    DECLARE_PROPERTY(Cfile32, m_f);
    Cmix_file* m_mix_f;
    bool m_is_open;
    int m_offset;
    int m_p;
    bool m_read_on_open; // const bool in fact
    int m_size;
};