






vector()
{
mid=(l+h)/2;
if(t[mid]==x)
returnmid;
elseif(t[mid]<x)
l=mid+1;
else
h=mid-1;
}
if(x<t[h])
returnh;
else
returnh+1;
}