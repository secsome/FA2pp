#pragma once

#include "cc_file_small.h"
#include "palet.h"

class Cpal_file : public Ccc_file_small
{
public:
	int extract_as_pal_jasc(const std::string& name) const;

	bool is_valid() const
	{
		if (get_size() != sizeof(t_palet))
			return false;
		const t_palet_entry* p = get_palet();
		for (int i = 0; i < 256; i++)
		{
			if ((p[i].r | p[i].g | p[i].b) & 0xc0)
				return false;
		}
		return true;
	}

	void decode(t_palet& palet) const
	{
		convert_palet_18_to_24(get_palet(), palet);
	}

	const t_palet_entry* get_palet() const
	{
		return reinterpret_cast<const t_palet_entry*>(get_data());
	}
};
