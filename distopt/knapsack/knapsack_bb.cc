#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct Item {
  long long m_value;
  long long m_weight;
  double m_ratio;

  Item(int v, int w) : m_value(v), m_weight(w)
  {
    m_ratio= static_cast<double>(m_value)/m_weight;
  }

  void p() {
    cout<<m_value<<"  "<<m_weight<<endl;
  }
};

struct ItemComparator {
  bool operator() (const Item& item1, const Item& item2) const
  {
    return item1.m_ratio > item2.m_ratio;
  }
};
struct Node {
 long long m_w;
 long long m_v;
 long long m_bound;
 int m_level;
 bool m_include;

 Node *m_left;
 Node *m_right;

 Node(long long w, long long v,
      long long bound, int level) : m_w(w), m_v(v),
                                    m_bound(bound), m_level(level),
                                    m_include(false),
                                    m_left(NULL), m_right(NULL)
  {
  }

};
int
main(int argc,char **argv)
{
  int n,w,c,v;
  cin>>n>>c;
  vector<Item> knapItems;
  for(int i= 0; i < n; i++) {
    cin>>v>>w;
    //Item it(v,w);
    knapItems.push_back(Item(v,w));
  }
  std::sort(knapItems.begin(), knapItems.end(), ItemComparator());
  vector<Item>::iterator kiter;
  cout<<n<<"   "<<c<<endl;
  for(kiter= knapItems.begin(); kiter != knapItems.end(); ++kiter)
    kiter->p();
  return 0;
}
