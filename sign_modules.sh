# assumes MOK.priv and MOK.der in the same folder, enrolled to secure-boot

for module in /lib/modules/$(uname -r)/kernel/drivers/video/nvidia*.ko
do
  echo "Signing ${module}..."
  sudo kmodsign sha512 MOK.priv MOK.der "$module" >> sign_results.out
done

