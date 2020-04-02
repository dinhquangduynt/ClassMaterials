<?php 
int $n=1000;
int $s=1;
if($n%2==0){
	for ($i=2; $i <= $n;$i=$i+2){
		$s*=$i;
	}
	echo "n!!= ".$s;
}

if ($n%2!=0) {
	for ($i=1; $i<= $n ; $i=$i+2) { 
		$s*=$i;
	}
	echo "n!!= ".$s;
}
 ?>