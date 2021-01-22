for(int i=0;i<arr.length;i++){
	visited[i] = 1;
	체크변수 ++;//이거대신 지역변수로?
	check();
	visited[i] = 1;
	체크변수 ++;
}
check(){
	if(체크변수 == k){
		max값 교체
	}else{
		위에반복
	}
}
