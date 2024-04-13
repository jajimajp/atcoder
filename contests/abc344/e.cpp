#include <bits/stdc++.h>

using namespace std;

#define ll long long


struct Ls {
  int val;
  Ls *next;
  Ls *prev;
};

int main() {
  int n;
  cin >> n;
  map<int, Ls*> pos;
  vector<int> al(n);
  Ls *cur = new Ls;
  Ls *head;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    al[i] = a;
    if (i == 0) {
      cur->val = a;
      pos.insert({a, cur});
      head = cur;
    } else {
      Ls *nxt = new Ls;
      nxt->prev = cur;
      nxt->val = a;
      cur->next = nxt;
      pos.insert({a, nxt});

      cur = nxt;
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int query;
    cin >> query;
    if (query == 1) {
      int x, y;
      cin >> x >> y;

      Ls *nxt = new Ls;
      nxt->val = y;
      pos.insert({y, nxt});
      Ls *xpos = pos[x];
      nxt->prev = xpos;
      nxt->next = xpos->next;
      xpos->next = nxt;
      if (nxt->next != NULL) {
        nxt->next->prev = nxt;
      }
    } else {
      int x;
      cin >> x;
      Ls *xpos = pos[x];
      pos.erase(x);
      if (xpos->prev != NULL) {
        xpos->prev->next = xpos->next;
      }
      if (xpos->next != NULL) {
        xpos->next->prev = xpos->prev;
      }
      if (head == xpos) {
        head = xpos->next;
      }
    }
  }

  cur = head;
  cout << cur->val;
  cur = cur->next;
  while (cur != NULL) {
    cout << " ";
    cout << cur->val;
    cur = cur->next;
  }
  cout << endl;
}