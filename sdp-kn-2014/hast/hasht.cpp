#include <string>
#include "hasht.h"

using namespace std;


template <class KeyType, class ValType>
HTRow<KeyType,ValType>::HTRow (const KeyType& k, const ValType& v):key(k),value(v),next(0){}


template <class KeyType, class ValType>
HashMap<KeyType,ValType>::HashMap (int capacity, int (*hfn) (KeyType,int))
{

}

template <class KeyType, class ValType>
HashMap<KeyType,ValType>::HashMap (const HashMap<KeyType,ValType>&)
{

}

template <class KeyType, class ValType>
HashMap<KeyType,ValType>& HashMap<KeyType,ValType>::operator = (const HashMap<KeyType,ValType>&){

	return *this;
}

	
template <class KeyType, class ValType>
void HashMap<KeyType,ValType>::addKeyValue (const KeyType&, const ValType&)
{

}

template <class KeyType, class ValType>
ValType HashMap<KeyType,ValType>::getValue (const KeyType&)
{
	return dummy;
}

template <class KeyType, class ValType>
ValType& HashMap<KeyType,ValType>::operator [] (const KeyType&)
{
	return dummy;

}


template <class KeyType, class ValType>
HashMap<KeyType,ValType>::~HashMap()
{

}
