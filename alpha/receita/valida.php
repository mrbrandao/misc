<!DOCTYPE html>
<html>
<head>
	<title>Valida Receita</title>
	<meta charset="UTF-8" />
</head>
<body>
	<h1>Validando Receita</h1>
	
	<?php
		//array para erros de validacao
		$erros = array();

		//validacao do nome
		if (trim($_GET['nome']) == ""){
			$erros[] = "O campo <b>NOME</b> é obrigatório!";
		}
		
		//validacao dos valores
		for ($i=1; $i <= 10; $i++) {
			if (!is_numeric(trim($_GET['valor'.$i]))){
				$erros[] = "O campo: <b>Valor".$i."</b> nao e um numero!";
			}

		}

		if (count($erros) != 0){
			//se forem encontrados erros
			echo "<br>Erros nos campos: <pre>";
			print_r($erros);

		}else {
			//gerar arquivo txt
			$file = fopen($_GET['nome'].'.txt', "w") or die("OPS... nao consegui gravar o arquivo");
			for ($i=1; $i <=10; $i++) {
				$txt = ($_GET['valor'.$i]).",".$txt;
			}
			fwrite($file, $txt.($_GET['descricao']));
			fclose($file);
			print_r("Tudo ok... <br><b>".($_GET['nome']).".txt</b> gravado com sucesso!");

		}

	?>
</body>
</html>