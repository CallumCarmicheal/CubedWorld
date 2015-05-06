# CubedWorld
Cube world is a fan project for creating a modding API for the acclaimed game 'Cube World' that has "Died" out and seems to not have updates any more until the year 2251, so we decided to try to create our own updates.

Status
======
Extremely early alpha, this stage is about getting all that we can to create a skeleton of what the api might be and by searching the game for calls that may be useful...

Why
======
Our poor fan favourite game is dying, no matter how we see it. The master-piece is going, so i and hopefully other developers will help me decompile and create a API like application that will allow us to make more use of this game and breath more life into it and bring it back to the market, the game may only be obtainable from pirating it but if the game is successful, I'm sure Picroma will reopen the store.

Pirating?
======
You didn't here it for me, im just saying the store is closed and you cant buy it.

Functions
======
List of all of the Cube World offsets I have found so far. Please note the function names are not the ones used in the source code, neither are the parameters, its what I can pull out from the ASM.
<table>
	<tr>
		<th>Memory Offset</th>
		<th>OPCODE/Hex/Machine Code</th>
		<th>ASSEMBLY</th>
		<th>Function</th>
		<th>Description</th>
	</tr>
	<tr>
		<td>015D7347</th>
		<td>F3 0F11 86 6C010000</th>
		<td>movss [esi+0000016C], xmm0</th>
		<td>evt_onPlayerEat(float regenAmt or Food-OBJ ref)</th>
		<td>This is called when ever the character eats Food.</th>
	</tr>
	<tr>
		<td>015DAB93</th>
		<td>F3 0F11 80 6C010000</th>
		<td>movss [eax+0000016C], xmm0</th>
		<td>evt_onPlayerFall(float damage)</th>
		<td>This is called when ever the player takes fall damage</th>
	</tr>
	<tr>
		<td>0155484B</th>
		<td>F3 0F11 86 6C010000</th>
		<td>movss [eax+0000016C], xmm0</th>
		<td>evt_onPlayerAttacked(float dam or entity-ref)</th>
		<td>This is called when the player takes damage of a entity/player</th>
	</tr>
</table>