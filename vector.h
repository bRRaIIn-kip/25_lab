#include <iostream>
template<typename T>
class vector
{
protected:
	T* arr;
	unsigned int Size;
public:
	vector(int s) :Size(s) { arr = new T[Size]; }
	vector() :Size(0) { arr = new T[Size]; }

	T& operator[](int index) { return arr[index]; }

	int size() { return Size; }
	vector operator* (int num)
	{
		vector rez;
		rez.arr = new T[Size];
		rez.Size = Size;
		for (int i = 0; i < Size; i++)
			rez.arr[i] = arr[i] * num;
		return rez;
	}

	vector operator+(const vector& other) const
	{
		vector<T> sum(Size < other.Size ? Size : other.Size);
		for (int i = 0; i < sum.size(); i++)
			sum.arr[i] = arr[i] + other.arr[i];
		return sum;
	}


	int operator-(int n) { if (n < Size)  return arr[n]; else return -1; }

	class Iterator {
	private:
		vector& Vector;
		size_t index;

	public:
		Iterator(vector& vec, size_t i) : Vector(vec), index(i) {}

		int operator*() const {
			return Vector.arr[index];
		}

		Iterator& operator++() {
			++index;
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return index != other.index;
		}
	};

	Iterator begin() { return Iterator(*this, 0); }

	Iterator end() { return Iterator(*this, Size); }

	void push_back(T value) {
		T* new_data = new T[Size + 1];
		for (int i = 0; i < Size; ++i) {
			new_data[i] = arr[i];
		}
		new_data[Size] = value;
		delete[] arr;
		arr = new_data;
		++Size;
	}
	void pop_back() 
	{
		T* new_data = new T[Size - 1];
		for (int i = 0; i < Size - 1; ++i) {
			new_data[i] = arr[i];
		}
		delete[] arr;
		arr = new_data;
		--Size;
	}
	const bool empty() {return Size == 0 ? true : false;}
	void Print() { for (int i = 0; i < Size; i++) std::cout << arr[i] << " "; std::cout << std::endl; }
	~vector() { delete[]arr; }
};
