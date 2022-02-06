#pragma once

#include "cc_file.h"
#include "cc_structures.h"

#include "../FA2PPCore.h"

class NOVTABLE Cmix_file : public Ccc_file
{
public:
	int post_open() { JMP_THIS(0x527C40) };
	t_file_type get_type(int id) { JMP_THIS(0x528A20) };
	xcc_string get_name(int id);
	static int get_id(t_game game, xcc_string name) { JMP_STD(0x528A40) };
	int get_index(unsigned int id) const { JMP_THIS(0x528C60) };
	bool is_valid();
	virtual void close() override { JMP_THIS(0x5289F0) };
	Cmix_file() { JMP_THIS(0x527C10) };

	void enable_mix_expansion()
	{
		m_mix_expansion = true;
	}

	int get_c_files() const
	{
		return m_c_files;
	}

	t_game get_game() const
	{
		return m_game;
	}

	void set_game(t_game game)
	{
		m_game = game;
	}

	int get_id(int index) const
	{
		return m_index[index].id;
	}

	int get_offset(unsigned int id) const
	{
		return m_index[get_index(id)].offset;
	}

	int get_size() const
	{
		return Ccc_file::get_size();
	}

	int get_size(unsigned int id) const
	{
		return m_index[get_index(id)].size;
	}

	bool has_checksum() const
	{
		return m_has_checksum;
	}

	bool is_encrypted() const
	{
		return m_is_encrypted;
	}
// private:
	// void clean_up();
	int m_c_files;
	t_game m_game;
	bool m_mix_expansion;
	bool m_is_encrypted;
	bool m_has_checksum;
	t_mix_index_entry* m_index;
	t_file_type* m_index_ft;
};