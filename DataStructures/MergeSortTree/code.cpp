//  Building the tree :
vector<int>tree[5*N];
int A[N];
Void build_tree( int cur , int l , int r )
{
     if( l==r )
     {
            tree[cur].push_back( a[ l ] );
            return ;
     }
     int mid = l+(r-l)/2;
     build_tree(2*cur+1 , l , mid ); // Build left tree 
     build_tree(2*cur+2 , mid+1 , r ); // Build right tree
     tree[cur] = merge( tree[2*cur+1] , tree[2*cur+2] ); //Merging the two sorted arrays
}

//Querying the tree :

int query( int cur, int l, int r, int x, int y, int k)
{
       if( r < x || l > y )
      {
               return 0; //out of range
      }
      if( x<=l && r<=y )
      {
              //Binary search over the current sorted vector to find elements smaller than K

              Return lower_bound(tree[cur].begin(),tree[cur].end(),K)-tree[cur].begin();
      }
      int mid=l+(r-l)/2;
     return query(2*cur+1,l,mid,x,y,k)+query(2*cur+2,mid+1,r,x,y,k);
}
