/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2010-2011, Christian Muehlhaeuser <muesli@tomahawk-player.org>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */
#include "Resolver.h"

#include "../resolvers/SyncScriptJob.h"
#include "../Result.h"

#include <QPixmap>


Tomahawk::Resolver::Resolver( QObject* parent )
    : QObject( parent )
{
}


QPixmap
Tomahawk::Resolver::icon( const QSize& ) const
{
    Q_ASSERT(false);
    return QPixmap();
}


Tomahawk::ScriptJob*
Tomahawk::Resolver::getStreamUrl( const result_ptr& result )
{
    QVariantMap data;
    data[ "url" ] = result->url();

    return new SyncScriptJob( data );
}
