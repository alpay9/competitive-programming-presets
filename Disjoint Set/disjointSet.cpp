
int find_set(vector<int>& ds, int x) {
    if (x == ds[x])
        return x;
    return ds[x] = find_set(ds[x]);
}

void union_set(vector<int>& ds, int x, int y) {
	x = find_set(x);
	y = find_set(y);
	if (x != y)
		ds[y] = x;
}
