<?php
    if(isset($_REQUEST['ok'])) {
        $search=addslashes($_GET['search']);
        if(empty($search)) {
            echo "Yeu cau nhap du lieu vao o trong";
        } else {
            $bienketnoi=mysqli_connect("127.0.0.1", "root", "") or die('Could not connect: '.mysqli_error());
            $db_selected=mysqli_select_db($bienketnoi, "DULIEU");
            $query="select * from phongban where IDPB like '%$search%' or TenPB like '%$search%' or MoTa like '%$search%'";
            $sql=mysqli_query($bienketnoi, $query);
            $num=mysqli_num_rows($sql);
            if($num > 0 && $search != "") {
                echo "$num ket qua tra ve voi tu khoa <b>$search</b>";
                echo "<table border = '1' width = '100%'>";
                echo "<caption>Du lieu truy xuat tu bang phongban</caption>";
                echo "<tr><th>IDPB</th><th>TenPB</th><th>MoTa</th></tr>";
                while($row = mysqli_fetch_assoc($sql)) {
                    $idpb = $row{'IDPB'};
                    $tenpb = $row{'TenPB'};
                    $mota = $row{'Mota'};
                    echo "<tr><td>$idpb</td><td>$tenpb</td><td>$mota</td></tr>";
                }
                echo '</table>';
            } else {
                echo "Khong tim thay ket qua!";
            }
        }
    }
?> 