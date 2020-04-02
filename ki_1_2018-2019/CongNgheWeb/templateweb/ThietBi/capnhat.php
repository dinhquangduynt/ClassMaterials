<?php
	$link=mysqli_connect('127.0.0.1', 'root', '') or die('Khong the ket noi den CSDL MySQL');
	mysqli_select_db($link, 'DULIEU');
	$sql='SELECT * FROM phongban';
	$result=mysqli_query($link, $sql);
	echo "<table border = '1' width = '100%'>";
	echo "<caption>Du lieu truy xuat tu bang phongban</caption>";
	echo "<tr><th>IDPB</th><th>TenPB</th><th>MoTa</th><th>ThayDoi</th></tr>";
	while($row=mysqli_fetch_array($result,true)) {
		$idpb = $row{'IDPB'};
		$tenpb = $row{'TenPB'};
		$mota = $row{'Mota'};
		//$thaydoi = $row{'ThayDoi'};
		echo "<tr><td>$idpb</td><td>$tenpb</td><td>$mota</td><td align = 'center'><a href = 'formcapnhat.php?IDPB=".$row['IDPB']."'>xxx</a></td></tr>";
	}
	echo "</table>";
?>