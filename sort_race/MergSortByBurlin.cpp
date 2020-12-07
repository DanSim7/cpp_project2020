#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void MergeSort(vector<int>& data, size_t first, size_t last)
{
	size_t left, right, middle, i; //� ������ ���������� ���������� ������
	vector<int> vec;
	size_t a = first + 1;

	if (last - first < 2) // �� ������ ���� � ������� 1 ��� 0 ��.
		return;
	if (last - first == 2) //���� � ������� 2 ��.
	{
		if (data[first] > data[a])
			swap(data[first], data[a]);
		return;
	}

	MergeSort(data, first, first + (last - first) / 2);
	MergeSort(data, first + (last - first) / 2, last);

	left = first;
	middle = first + (last - first) / 2;
	right = middle ;

	while (vec.size() < last - first)
	{
		if (left >= middle || (right < last && data[right] <= data[left]))
		{
			vec.push_back(data[right]);
			++right;
		}
		else
		{
			vec.push_back(data[left]);
			++left;
		}
	}

	for (i = first; i < last; ++i)
	{
		size_t b = i - first;
		data[i] = vec[b];
	}
}

vector<int> merge_sort(vector<int> data)
{
	MergeSort(data, 0, data.size() - 1);
	return data;
}


/*
int main()
{
	vector<int> v;
	for (int i = 0; i < 20; ++i)
		v.push_back(i);
	for (size_t i = 0; i < v.size(); ++i)
		swap(v[i], v[rand() % (v.size() - i) + i]);
	for (auto i : v)
		cout << i << " ";
	cout << endl;

	MergeSort(v, 0, v.size());
	for (auto i : v)
		cout << i << " ";
	cout << endl;

}


void merge(vector<int>& data, int first, int last) 
{
	int left_it, right_it, middle, j;
	int *mas; //���������� ������������� ����
	mas = (int*)malloc((last - first) * sizeof(int)); //��������� ���������������� ������� ������ ������� ������� �� ������������������ ������ 
	                                                 //(������ - ������� ���������� � ������� ��������)

	middle = (first + last) / 2;
	left_it = first;
	right_it = middle + 1;

	for (j = first; j <= last; j++) //����, �������� �������� ��������� �� ������� ������ �� ������� �����
		if ((left_it <= middle) && ((right_it > last) || (data[left_it] < data[right_it])))
		{
			*(mas + j - first) = data[left_it];
			left_it++;
		}
		else
		{
			*(mas + j - first) = data[left_it];
			right_it++;
		}
	//����������� ���������� � ������
	for (j = first; j <= last; j++) data[j] = *(mas + j - first);
};
	
void MergeSort(vector<int>& data, int first, int last)
{
	{
		if (first < last)
		{
			MergeSort(data, first, (first + last) / 2); //���������� ������(�����) �����
			MergeSort(data, (first + last) / 2 + 1, last); //���������� ���������(������) �����
			merge(data, first, last); //������� ���� ������
		}
	}
}; 


vector<int> merge_sort(vector<int> data)
{
	MergeSort(data, 0,  data.size() - 1);
	return data;
}
*/