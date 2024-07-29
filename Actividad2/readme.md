## Datos
* Nombre: Kevin Martin Samayoa Urizar
* Carnet: 200915348
* Fecha: 28/07/2024

## Descripción del script

Primero se define el encabezado llamado Shebang (Para definir que será un script de bash)
    
    #! /usr/bin/env bash

 Se establece la acción detener el script, si ocurre un error
  
    set -o errexit

Se lee el id de la cuenta github. En este caso `kmsu` 

      GITHUB_USER='kmsu'

Se consulta el sitio web de github, luego con el comando `jq` se extrae los datos deseados y se almacenan los valores en las variables `github_user`, `github_id` y `github_create_at`

    github_user=$(curl -s https://api.github.com/users/$GITHUB_USER | jq '.name')
    github_id=$(curl -s https://api.github.com/users/$GITHUB_USER | jq '.id')
    github_create_at=$(curl -s https://api.github.com/users/$GITHUB_USER | jq '.created_at')

Se remueven las comillas dobles de los campos de texto en las variables `github_create_at` y `github_user`

    github_user=$(sed -e 's/^"//' -e 's/"$//' <<<"$github_user") 
    github_create_at=$(sed -e 's/^"//' -e 's/"$//' <<<"$github_create_at")

Se crea la carpeta temporal con la fecha del día actual (hoy). Para ello se utiliza una sentencia `if` para validar que la carpeta exista

    if [[ ! -d "/tmp/$(date +'%d-%m-%Y')" ]]
    then
    mkdir /tmp/$(date +"%d-%m-%Y") 
    fi

Se imprime la salida con el comando `echo`
    
    echo "Hola $github_user, User ID: $github_id, Cuenta fue creada el: $github_create_at." 

Para finalizar, se realiza la concatenación de la cadena anterior en el archivo `saludo.log`

    echo "Hola $github_user, User ID: $github_id, Cuenta fue creada el: $github_create_at." \
    >> /tmp/$(date +"%d-%m-%Y")/saludos.log

Salida del script en bash 

![Salida del script con bash](https://github.com/kmsu/so1_actividades_200915348/blob/main/Actividad2/Imagenes/SalidaScript.png)

## Cron Job
### Pasos para instalar Cron Job en Ubuntu 22.04.3 LTS 
#### Para todo lo descrito a continuación se utiliza una terminal del SO.

Primero paso: Se debe preparar el sistema operativo

1. Actualizar el índice de paquetes locales del sistema operativo

       sudo apt update
   
3. Actualizar los repositorios del sistema a su ultima versión

       sudo apt upgrade
   
Segundo paso: Instalar Cron Job utilizando una terminal del SO

    sudo apt install cron 

Se debe establecer Cron Job como una función en segundo plano

    sudo systemctl enable cron

Tercer paso: Editar un archivo Cron Job

Se abre un editor de de Cron Job utilizando el comando `crontab -e`

Se debe posicionar al final del archivo Cron Job (usando las flechas del teclado) y escribir 

    5 * * * * /home/kevin/Documentos/2S2024/Sopes1/Clase/Actividad2/Actividad2.sh

El patrón `5 * * * *` Especifica que el script se ejecute cada 5 minutos. 

![Editando Cron Job](https://github.com/kmsu/so1_actividades_200915348/blob/main/Actividad2/Imagenes/EditCrontab.png)

Descripción de los campos (de izquierda a derecha)
* Minutos (0-59)
* Horas (0-23)
* Día del mes (1-31)
* Mes (1-12)
* Día de la semana (0-7) (0 y 7 representan el domingo)

Cada uno de estos datos deben ser escritos de forma continua y separados por un espacio, para luego ser ejecutados.

El asterisco (*) en cada campo representa que cada cambio en el parametro se debe realizar alguna acción. Por lo tanto, el `5` en el campo de los minutos indica que se ejecutará cada 5 minutos.

Seguido del patron se escribe la `ruta/script` a ajecutar, en este caso `Actividad2.sh`

Una vez editado el Cron Job presionar `Ctrl+o` para guardar y luego `Ctrl+x` para salir y el Cron Job se ejecutará según lo especificado.

#Verificación de ejecucion

Con el comando `crontab -l` se listan los Cron Job en ejecución

![Cron Job Actividad2](https://github.com/kmsu/so1_actividades_200915348/blob/main/Actividad2/Imagenes/ComprobarCrontab.png)

Con el comando `crontab -r` se eliminan los Cron Job actuales

![Eliminacion del Cron Job Actividad2](https://github.com/kmsu/so1_actividades_200915348/blob/main/Actividad2/Imagenes/EliminarCrontab.png)

Anexo: Archivo `saludo.log` desde `/tmp` con 4 ejecuciones del script

![saludo.log](https://github.com/kmsu/so1_actividades_200915348/blob/main/Actividad2/Imagenes/SaludosLog.png)





