# your code goes here
def smallestpositive(arr):
    j = 1
    arrr = []
    array=arr.split(',')
    for i in array:
        arrr.append(int(i))
    arrr.sort()
    #print arrr
    #n=len(arrr)
    #print n
    for elem in arrr:
    	if elem>0:
    		if elem == j:
    			j += 1
    		else:
    			return j
    return j
    
print smallestpositive("8,2,4,1,5,-1")