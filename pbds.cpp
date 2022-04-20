#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
	ordered_set<pair<int, int>> os;
	os.insert({5, 1});
	os.insert({6, 2});
	os.insert({4, 3});
	os.insert({1, 4});
	cout << os.order_of_key({4,-1});  // values strictly less than 4(1);
	cout << os.order_of_key({5,-1});  // values strictly less than 5(2);
	cout << os.find_by_order(i)->first; // iterator of ith element;
	return 0;
}
