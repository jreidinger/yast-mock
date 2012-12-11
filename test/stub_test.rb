require "test/unit"

require "ycp"
require "ycp/mock"
require "ycp/http_server"

class StubTest < Test::Unit::TestCase

  def test_simple_stub
    YCP::Mock.stub "Package::InstalledAny", true
    assert_equal ({"install"=>["apache2"], "remove"=>[]}),
                  YCP::HttpServer.AutoPackages
    YCP::Mock.stub "Package::InstalledAny", false
    assert_equal ({"install"=>["apache2", "apache2-prefork"], "remove"=>[]}),
                  YCP::HttpServer.AutoPackages
  end
end
