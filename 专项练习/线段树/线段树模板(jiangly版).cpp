#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct Tag
{
    i64 add = 0; // 懒标记：整段加 add

    void apply(const Tag &t)
    {                 // 合并标记
        add += t.add; // 先加当前标记，再加新标记
    }
};

struct Info
{
    i64 sum = 0; // 区间和
    int len = 1; // 区间长度

    void apply(const Tag &t)
    {                       // 给当前整段应用标记
        sum += t.add * len; // 整段加 t.add，区间和增加 t.add * len
    }
};

Info operator+(const Info &a, const Info &b)
{                          // 合并两个子区间信息
    Info c;                // 新节点信息
    c.sum = a.sum + b.sum; // 区间和相加
    c.len = a.len + b.len; // 区间长度相加
    return c;              // 返回合并结果
}

template <class Info, class Tag>
struct LazySegmentTree
{
    int n;             // 数组长度
    vector<Info> info; // 线段树节点信息
    vector<Tag> tag;   // 懒标记

    LazySegmentTree() {} // 默认构造

    LazySegmentTree(int n)
    {            // 按长度建树
        init(n); // 初始化
    }

    template <class T>
    LazySegmentTree(const vector<T> &a)
    {            // 按数组建树
        init(a); // 初始化
    }

    void init(int n)
    {                                      // 初始化空树
        this->n = n;                       // 记录长度
        info.assign(4 << __lg(n), Info()); // 开空间存节点信息
        tag.assign(4 << __lg(n), Tag());   // 开空间存懒标记
        build(1, 0, n);                    // 建树
    }

    template <class T>
    void init(const vector<T> &a)
    {                                      // 用数组初始化
        n = a.size();                      // 记录长度
        info.assign(4 << __lg(n), Info()); // 开空间存节点信息
        tag.assign(4 << __lg(n), Tag());   // 开空间存懒标记
        build(1, 0, n, a);                 // 根据数组建树
    }

    void pull(int p)
    {                                              // 用左右儿子更新当前节点
        info[p] = info[p << 1] + info[p << 1 | 1]; // 合并左右儿子
    }

    void apply(int p, const Tag &v)
    {                     // 给节点 p 应用标记 v
        info[p].apply(v); // 更新节点信息
        tag[p].apply(v);  // 合并懒标记
    }

    void push(int p)
    {                              // 下传懒标记
        apply(p << 1, tag[p]);     // 标记传给左儿子
        apply(p << 1 | 1, tag[p]); // 标记传给右儿子
        tag[p] = Tag();            // 清空当前节点标记
    }

    void build(int p, int l, int r)
    { // 建空树，节点 p 表示 [l, r)
        if (r - l == 1)
        {                    // 到达叶子
            info[p].len = 1; // 叶子长度为 1
            return;          // 返回
        }

        int m = (l + r) / 2;     // 取中点
        build(p << 1, l, m);     // 建左儿子
        build(p << 1 | 1, m, r); // 建右儿子
        pull(p);                 // 更新当前节点
    }

    template <class T>
    void build(int p, int l, int r, const vector<T> &a)
    { // 用数组建树
        if (r - l == 1)
        {                       // 到达叶子
            info[p].sum = a[l]; // 叶子值
            info[p].len = 1;    // 叶子长度为 1
            return;             // 返回
        }

        int m = (l + r) / 2;        // 取中点
        build(p << 1, l, m, a);     // 建左儿子
        build(p << 1 | 1, m, r, a); // 建右儿子
        pull(p);                    // 更新当前节点
    }

    void modify(int p, int l, int r, int x, const Info &v)
    { // 单点修改，把 x 改成 v
        if (r - l == 1)
        {                // 到达叶子
            info[p] = v; // 修改节点信息
            return;      // 返回
        }

        int m = (l + r) / 2; // 取中点
        push(p);             // 先下传懒标记

        if (x < m)
        {                               // x 在左儿子
            modify(p << 1, l, m, x, v); // 修改左儿子
        }
        else
        {                                   // x 在右儿子
            modify(p << 1 | 1, m, r, x, v); // 修改右儿子
        }

        pull(p); // 修改后更新当前节点
    }

    void modify(int x, const Info &v)
    {                          // 单点修改对外接口
        modify(1, 0, n, x, v); // 从根节点开始修改
    }

    Info rangeQuery(int p, int l, int r, int x, int y)
    { // 查询 [x, y)，当前节点是 [l, r)
        if (l >= y || r <= x)
        {                  // 无交集
            return Info(); // 返回空信息
        }

        if (l >= x && r <= y)
        {                   // 当前区间被完全覆盖
            return info[p]; // 直接返回当前节点信息
        }

        int m = (l + r) / 2; // 取中点
        push(p);             // 查询前下传懒标记

        return rangeQuery(p << 1, l, m, x, y) + rangeQuery(p << 1 | 1, m, r, x, y); // 合并左右查询结果
    }

    Info rangeQuery(int l, int r)
    {                                     // 区间查询对外接口
        return rangeQuery(1, 0, n, l, r); // 查询 [l, r)
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &v)
    { // 对 [x, y) 应用标记 v
        if (l >= y || r <= x)
        {           // 无交集
            return; // 不处理
        }

        if (l >= x && r <= y)
        {                // 当前区间被完全覆盖
            apply(p, v); // 直接应用标记
            return;      // 返回
        }

        int m = (l + r) / 2; // 取中点
        push(p);             // 修改前下传懒标记

        rangeApply(p << 1, l, m, x, y, v);     // 递归修改左儿子
        rangeApply(p << 1 | 1, m, r, x, y, v); // 递归修改右儿子

        pull(p); // 修改后更新当前节点
    }

    void rangeApply(int l, int r, const Tag &v)
    {                                 // 区间修改对外接口
        rangeApply(1, 0, n, l, r, v); // 修改 [l, r)
    }

    template <class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred)
    { // 在 [x, y) 找第一个满足 pred 的位置
        if (l >= y || r <= x || !pred(info[p]))
        {              // 无交集或整段不满足
            return -1; // 找不到
        }

        if (r - l == 1)
        {             // 到达叶子
            return l; // 返回位置
        }

        int m = (l + r) / 2; // 取中点
        push(p);             // 下传懒标记

        int res = findFirst(p << 1, l, m, x, y, pred); // 优先在左儿子找
        if (res == -1)
        {                                                  // 左边找不到
            res = findFirst(p << 1 | 1, m, r, x, y, pred); // 去右儿子找
        }

        return res; // 返回答案
    }

    template <class F>
    int findFirst(int l, int r, F &&pred)
    {                                          // findFirst 对外接口
        return findFirst(1, 0, n, l, r, pred); // 在 [l, r) 中找
    }

    template <class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred)
    { // 在 [x, y) 找最后一个满足 pred 的位置
        if (l >= y || r <= x || !pred(info[p]))
        {              // 无交集或整段不满足
            return -1; // 找不到
        }

        if (r - l == 1)
        {             // 到达叶子
            return l; // 返回位置
        }

        int m = (l + r) / 2; // 取中点
        push(p);             // 下传懒标记

        int res = findLast(p << 1 | 1, m, r, x, y, pred); // 优先在右儿子找
        if (res == -1)
        {                                             // 右边找不到
            res = findLast(p << 1, l, m, x, y, pred); // 去左儿子找
        }

        return res; // 返回答案
    }

    template <class F>
    int findLast(int l, int r, F &&pred)
    {                                         // findLast 对外接口
        return findLast(1, 0, n, l, r, pred); // 在 [l, r) 中找
    }
};

int mian()
{
    LazySegmentTree<Info, Tag> seg(a); // 用数组 a 建树

    seg.rangeApply(l, r, Tag{x}); // 对 [l, r) 全部加 x

    cout << seg.rangeQuery(l, r).sum << '\n'; // 查询 [l, r) 的区间和

    return;
}