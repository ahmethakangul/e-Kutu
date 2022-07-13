<?php			
	ob_start();
	date_default_timezone_set('Europe/Istanbul');
	$bag = mysqli_connect("127.0.0.1","root","");
	
	if (!$bag)
		  {
		  die('Bağlantı yapılamadı. Nedeni: ' . mysqli_error());
		  }
		  
		mysqli_select_db($bag, 'ids');


?>