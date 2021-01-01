// set standard header

#include "FATree.h"

#ifdef  _MSC_VER
#pragma pack(push,8)
#endif  /* _MSC_VER */

// TEMPLATE CLASS set
template<class _K, DWORD nil_addr, DWORD nilrefs_addr, 
	class _Pr = std::less<_K>, class _A = std::allocator<_K> >
	class FASet {
	public:
		typedef FASet<_K, _Pr, _A> _Myt;
		typedef _K value_type;
		struct _Kfn : public unary_function<value_type, _K> {
			const _K& operator()(const value_type& _X) const
			{
				return (_X);
			}
		};
		typedef _Pr value_compare;
		typedef _K key_type;
		typedef _Pr key_compare;
		typedef _A allocator_type;
		typedef typename FATree<_K, value_type, _Kfn, _Pr, _A, nil_addr, nilrefs_addr> _Imp;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename _Imp::iterator iterator;
		typedef std::pair<iterator, bool> _Pairib;
		typedef std::pair<iterator, iterator> _Pairii;
		explicit FASet(const _Pr& _Pred = _Pr(), const _A& _Al = _A())
			: _Tr(_Pred, false, _Al) {}
		typedef const value_type* _It;
		FASet(_It _F, _It _L, const _Pr& _Pred = _Pr(),
			const _A& _Al = _A())
			: _Tr(_Pred, false, _Al)
		{
			for (; _F != _L; ++_F)
				_Tr.insert(*_F);
		}
		iterator begin() const
		{
			return (_Tr.begin());
		}
		iterator end() const
		{
			return (_Tr.end());
		}
		size_type size() const
		{
			return (_Tr.size());
		}
		size_type max_size() const
		{
			return (_Tr.max_size());
		}
		bool empty() const
		{
			return (_Tr.empty());
		}
		_A get_allocator() const
		{
			return (_Tr.get_allocator());
		}
		_Pairib insert(const value_type& _X)
		{
			_Imp::_Pairib _Ans = _Tr.insert(_X);
			return (_Pairib(_Ans.first, _Ans.second));
		}
		iterator insert(iterator _P, const value_type& _X)
		{
			return (_Tr.insert((_Imp::iterator&)_P, _X));
		}
		void insert(_It _F, _It _L)
		{
			for (; _F != _L; ++_F)
				_Tr.insert(*_F);
		}
		iterator erase(iterator _P)
		{
			return (_Tr.erase((_Imp::iterator&)_P));
		}
		iterator erase(iterator _F, iterator _L)
		{
			return (_Tr.erase((_Imp::iterator&)_F,
				(_Imp::iterator&)_L));
		}
		size_type erase(const _K& _Kv)
		{
			return (_Tr.erase(_Kv));
		}
		void clear()
		{
			_Tr.clear();
		}
		void swap(_Myt& _X)
		{
			std::swap(_Tr, _X._Tr);
		}
		friend void swap(_Myt& _X, _Myt& _Y)
		{
			_X.swap(_Y);
		}
		key_compare key_comp() const
		{
			return (_Tr.key_comp());
		}
		value_compare value_comp() const
		{
			return (_Tr.key_comp());
		}
		iterator find(const _K& _Kv) const
		{
			return (_Tr.find(_Kv));
		}
		size_type count(const _K& _Kv) const
		{
			return (_Tr.count(_Kv));
		}
		iterator lower_bound(const _K& _Kv) const
		{
			return (_Tr.lower_bound(_Kv));
		}
		iterator upper_bound(const _K& _Kv) const
		{
			return (_Tr.upper_bound(_Kv));
		}
		_Pairii equal_range(const _K& _Kv) const
		{
			return (_Tr.equal_range(_Kv));
		}
	protected:
		_Imp _Tr;
};
// set TEMPLATE OPERATORS
template<class _K, DWORD nil_addr, DWORD nilrefs_addr, class _Pr, class _A> inline
bool operator==(const FASet<_K, nil_addr, nilrefs_addr,_Pr, _A>& _X,
	const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _Y)
{
	return (_X.size() == _Y.size()
		&& equal(_X.begin(), _X.end(), _Y.begin()));
}
template<class _K, DWORD nil_addr, DWORD nilrefs_addr, class _Pr, class _A> inline
bool operator!=(const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _X,
	const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _Y)
{
	return (!(_X == _Y));
}
template<class _K, DWORD nil_addr, DWORD nilrefs_addr, class _Pr, class _A> inline
bool operator<(const const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _X,
	const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _Y)
{
	return (lexicographical_compare(_X.begin(), _X.end(),
		_Y.begin(), _Y.end()));
}
template<class _K, DWORD nil_addr, DWORD nilrefs_addr, class _Pr, class _A> inline
bool operator>(const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _X,
	const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _Y)
{
	return (_Y < _X);
}
template<class _K, DWORD nil_addr, DWORD nilrefs_addr, class _Pr, class _A> inline
bool operator<=(const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _X,
	const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _Y)
{
	return (!(_Y < _X));
}
template<class _K, DWORD nil_addr, DWORD nilrefs_addr, class _Pr, class _A> inline
bool operator>=(const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _X,
	const FASet<_K, nil_addr, nilrefs_addr, _Pr, _A>& _Y)
{
	return (!(_X < _Y));
}

#ifdef  _MSC_VER
#pragma pack(pop)
#endif  /* _MSC_VER */