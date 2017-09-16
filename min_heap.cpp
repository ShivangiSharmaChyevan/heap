#include<iostream>
#include<climits>
using namespace std;

class heap
{
        int *arr;
        int size;
        int cap;
        
        public:
        
        heap(int c)
        {
                cap=c;
                
                size=0;
                
                arr=new int[cap];
        }
        
        int left(int i)
        {
                return (2*i+1);
        }
        
        int right(int i)
        {
                return (2*i+2);
        }
        
        int parent(int i)
        {
                return((i-1)/2);
        }
        
        void minheapify(int);
        
        int extractmin();
        
        void chng_val(int i,int val);
        
        int getmin()
        {
                return arr[0];
        }
        
        void delet(int i);
        
        void insert(int i);
        
};

void swap(int *a,int *b)
{
        int c=*a;
        *a=*b;
        *b=c;

}
void heap::chng_val(int i,int val)
{
        arr[i]=val;
        
        while(i!=0 && arr[parent(i)]>arr[i])
        {
                swap(&arr[parent(i)],&arr[i]);
                i=parent(i);
        }
}
void heap::minheapify(int i)
{
        int l=left(i);
        int r=right(i);
 
        int smallest=i;
        
        if(l<size && arr[l]<arr[i])
        smallest=i;
        
        if(r<size && arr[r]<arr[smallest])
        smallest=r;
        
        if(smallest!=i)
        {
        swap(&arr[smallest],&arr[i]);  
        minheapify(smallest);     
        }
 
}

void heap::insert(int val)
{
       if(size==cap)
       {
                cout<<"\n Overflow";
                return ;
       }
       size++;
       arr[size-1]=val;
       int i=size-1;
       while(i!=0 && arr[parent(i)]>arr[i])
       {
                      swap(&arr[parent(i)],&arr[i]);
                      i=parent(i);
       }
       for(int j=0;j<size;++j)
    cout<<arr[j]<<" ";
    cout<<"\n";
}
int heap::extractmin()
{
         
         
        if(size<=0)
        {
                return INT_MAX;
        }
         if(size==1)
        {
                size--;
                return arr[0];
        }
        
       
        else
        {
               int root=arr[0];
                arr[0]=arr[size-1];
                size--;
                minheapify(0);
                return root;
        }
        
        
}
void heap::delet(int i)
{
        chng_val( i,INT_MIN);
        extractmin();
        
}
int main()
{
   heap h(11);
    h.insert(3);
    h.insert(2);
    h.delet(1);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    
    cout << h.extractmin() << " ";
    cout << h.getmin() << " ";
    h.chng_val(2, 1);
    cout << h.getmin();
    return 0;
}
