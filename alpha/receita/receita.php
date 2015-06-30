<!DOCTYPE html>
<html>
<head>
	<title>Receita</title>
</head>
<body>
	<h1>Receita</h1>
	<form action="valida.php" method="get" enctype="multipart/form-data">
		
		<label for="nome">Nome:</label>
		<input type="text" name="nome" value="<?php echo $_GET['nome'];?>" id="nome" maxlegth="20" required="required" />
		</p>

		<label for="valor1">Valor1:</label>
		<input type="number" name="valor1" value="<?php echo $_GET['valor1'];?>" id="valor1" maxlegth="14" required="required" />
		</p>

		<label for="valor2">Valor2:</label>
		<input type="number" name="valor2" value="<?php echo $_GET['valor2'];?>" id="valor2" maxlegth="14" required="required" />
		</p>

		<label for="valor3">Valor3:</label>
		<input type="number" name="valor3" value="<?php echo $_GET['valor3'];?>" id="valor3" maxlegth="14" required="required" />
		</p>

		<label for="valor4">Valor4:</label>
		<input type="number" name="valor4" value="<?php echo $_GET['valor4'];?>" id="valor4" maxlegth="14" required="required" />
		</p>

		<label for="valor5">Valor5:</label>
		<input type="number" name="valor5" value="<?php echo $_GET['valor5'];?>" id="valor5" maxlegth="14" required="required" />
		</p>

		<label for="valor6">Valor6:</label>
		<input type="number" name="valor6" value="<?php echo $_GET['valor6'];?>" id="valor6" maxlegth="14" required="required" />
		</p>

		<label for="valor7">Valor7:</label>
		<input type="number" name="valor7" value="<?php echo $_GET['valor7'];?>" id="valor7" maxlegth="14" required="required" />
		</p>

		<label for="valor8">Valor8:</label>
		<input type="number" name="valor8" value="<?php echo $_GET['valor8'];?>" id="valor8" maxlegth="14" required="required" />
		</p>

		<label for="valor9">Valor9:</label>
		<input type="number" name="valor9" value="<?php echo $_GET['valor9'];?>" id="valor9" maxlegth="14" required="required" />
		</p>

		<label for="valor10">Valor10:</label>
		<input type="number" name="valor10" value="<?php echo $_GET['valor10'];?>" id="valor10" maxlegth="14" required="required" />
		</p>

		<label for="descricao">Descricao:</label>
		<input type="text" name="descricao" value="<?php echo $_GET['descricao'];?>" id="descricao" maxlegth="140" required="required" />

		<input type="submit" value="Enviar" />
	</form>
</body>
</html>