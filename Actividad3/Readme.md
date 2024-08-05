|              |                |
|    :---      |      ---:      |
| Nombre: Kevin Martin Samayoa Urizar | Curso: Sistemas Operativos 1 |
| Carnet: 200915348                   | Fecha: 04/08/2024            |

# ACTIVIDAD 3

## Contenido
- [Parte 1: Gestión de Usuarios](#usuarios)
- [Parte 2: Gestión de Usuarios](#grupos)
- [Parte 3: Gestión de Usuarios](#permisos)
- [Reflexión](#reflexion)

---

<a name="usuarios"></a>
## Parte 1: Gestión de Usuarios 

1. Creación de Usuarios: Crea tres usuarios llamados `usuario1`, `usuario2`, `usuario3`.
![CrearUsuarios](Imagenes/CrearUsuarios.png)

2. Asignación de Contraseñas: Establece una nueva contraseña para cada usuario creado.
![EstablecerNuevaContraseña](Imagenes/AsignarPass.png)

3. Información de Usuarios: Muestra la información de `usuario1` usando el comando `id`.
![ComandoId_user1](Imagenes/CmdId_user1.png)

4. Eliminación de Usuarios: Elimina `usuario3`, pero conserva su directorio principal.
![DeleteUser3](Imagenes/DelUser3.png)
![DeleteUser3Id](Imagenes/DelIdUser3.png)

---

<a name="grupos"></a>
## Parte 2: Gestión de Grupos 

1. Creación de Grupos: Crea dos grupos llamados `grupo1` y `grupo2`.
![AddGrupos](Imagenes/AddGrupos.png)

2. Agregar Usuarios a Grupos: Agrega `usuario1` a `grupo1` y `usuario2` a `grupo2`.
![AddUsersToGroups](Imagenes/AddUsersToGroups.png)

3. Verificar Membresía: Verifica que los usuarios han sido agregados a los grupos utilizando el comando `groups`.
![MembresiasGrupos](Imagenes/MembresiasGrupos.png)

4. Eliminar Grupo: Elimina `grupo2`.
![DelGrupo2](Imagenes/DelGrupo2.png)
![DelGrupo2Verificado](Imagenes/DelGrupo2Verificado.png)

---

<a name="permisos"></a>
## Parte 3: Gestión de Permisos

1. Creación de Archivos y Directorios:
    
    Como `usuario1`, crea un archivo llamado `archivo1.txt` en su directorio principal y escribe algo en él.
![CreandoArchivo](Imagenes/CrearArchivoUser1.png)
![Editando el archivo](Imagenes/Archivo1.png)

    Crea un directorio llamado `directorio1` y dentro de ese directorio, un archivo llamado `archivo2.txt`.
    ![Directorio1 archivo2](Imagenes/Directorio1.png)

2. Verificar Permisos: Verifica los del archivo y directorio usando `ls -l` y `ls -ld` respectivamente.
![Verificar permisos](Imagenes/VerificarPermisos.png)

3. Modificar Permisos usando `chmod` con Modo Numérico: Cambia los permisos del `archivo1.txt` para que sólo `usuario1` pueda leer y escribir (permisos `rw-`), el grupo pueda leer (permisos `r--`) y nadie más pueda hacer nada.
![Permisos archivo1.txt](Imagenes/PermisosArchivo1.png)

4. Modificar Permisos usando `chmod` con Modo Simbólico: Agrega permiso de ejecución al propietario del `archivo2.txt`.
![Modo simbolico](Imagenes/ModoSimbolico.png)

5. Cambiar el Grupo Propietario: Cambia el grupo propietario de `archivo2.txt` a `grupo1`.
![Grupo propietario](Imagenes/GrupoPropietario.png)

6. Configurar Permisos de Directorio: Cambia los permisos del `directorio1` para que sólo el propietario pueda entrar (permisos `rwx`), el grupo pueda listar contenidos pero no entrar (permisos `r--`), y otros no puedan hacer nada.
![Permisos directorio](Imagenes/PermisosDirectorio.png)

7. Comprobación de Acceso: Intenta acceder al `archivo1.txt` y `directorio1/archivo2.txt` como `usuario2`. Nota cómo el permiso de directorio afecta el acceso a los archivos dentro de él.
![Comprobacion de acaceso](Imagenes/ComprobacionAcceso.png)

8. Verificación Final: Verifica los permisos y propietario de los archivos y directorio nuevamente con `ls -l` y `ls -ld`.
![Verificacion Usuario1](Imagenes/VerificacionUsuario1.png)
![Verificacion Usuario2](Imagenes/VerificacionUsuario2.png)

<a name="reflexion"></a>
## Reflexión

Contestar las siguientes pregunta:

1. ¿Por qué es importante gestionar correctamente los usuarios y permisos en un sistema operativo?

Para mantener la seguridad, estabilidad, eficiencia y el cumplimiento de normas y regulaciones que puedan existir en determinados lugares.

2. ¿Qué otros comandos o técnicas conocen para gestionar permisos en Linux?

- usermod: Modifica un usuario por ejemplo, agregarlo al grupo sudo para darle permisos de sudo si fuera necesario.

