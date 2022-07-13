<?php
include('ayar1453.php');
?>
<html>
<head>
<link rel="stylesheet" type="text/css" href="style.css">
<title>e-Kutu</title>
</head>
<body>
    <table><tr><a href="https://www.afad.gov.tr" target="_blank"><img class="elogo" src="img/ekutu.png" alt=""></a></tr></table> 
	<table><tr><a href="index.php"><img class="admin" src="img/admin.png" alt=""></a></tr></table>
	
   <form class="form" name="form"  action="index.php" method="post"  >
     <table border="0" width="100%" height="100%"> <tr><td>
	 <table><tr><img class="login" src="img/login.png" alt=""></tr> </table>    
      <table border="0" width="20%" height="40%">
	  <tr><td >  
	  <b> Kullanıcı Adı:</b><br /> <input type="text" name="isim" size="24">
	  <br /><br />       
	   
      <b> Şifre:</b><br /> 
      <input type="password" name="sifre" size="16">
	  <br /><br /><br /><br />
	  
      <input type="submit" name="gonder" value="Gönder" ><br /><br />
	  
	  
			  <?php
			if (isset($_POST['gonder'])){
			$ad = $_POST['isim'];
			$sifre = $_POST['sifre'];
			$gelennesnesi = mysqli_query($bag,"SELECT * FROM kullanicilar WHERE kAdi='$ad' and kSifre='$sifre'");
			if(mysqli_num_rows($gelennesnesi)==0){
				echo 'Kullanıcı adı veya şifre yanlış!';
			}
			else{  
			session_start();
			$dizi= mysqli_fetch_row($gelennesnesi);
			
			$_SESSION["kId"]= md5($dizi[0]);
			header('Location: goster.php');

				
			}
				
			}
			
			?>
	  </td></tr>
       </td></tr>
   </table>
   
   </form>
      

</body>

</html>