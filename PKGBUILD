pkgname=tascam-gtk
_gitname=tascam-gtk
pkgver=1
pkgrel=1
pkgdesc="GTK+ based application to control Tascam US-16x08 DSP mixer"
arch=('i686' 'x86_64')
url="https://github.com/onkelDead/tascam-gtk"
license=('MIT')
depends=('libxml++2.6')
makedepends=('git')
source=(git://github.com/onkelDead/${_gitname}.git)
sha1sums=(SKIP)


build() {
  cd ${_gitname}
  ./configure
  make
}

package() {
  cd ${_gitname}
  make DESTDIR=${pkgdir} install
}
